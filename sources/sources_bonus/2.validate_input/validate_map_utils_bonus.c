/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:47:17 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/19 14:21:24 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

void	get_player_coordinates(t_map *map, int rows, int coll)
{
	map->player.x = coll;
	map->player.y = rows;
	if (map->map[rows][coll] == 'N')
		map->player_dir = NORTH;
	if (map->map[rows][coll] == 'S')
		map->player_dir = SOUTH;
	if (map->map[rows][coll] == 'E')
		map->player_dir = EAST;
	if (map->map[rows][coll] == 'W')
		map->player_dir = WEST;
	map->map[rows][coll] = '0';
}

void	get_enemy_coordinates_aux(t_enemy *enemy)
{
	enemy->left.x = 0;
	enemy->left.y = 0;
	enemy->right.x = 0;
	enemy->right.y = 0;
	enemy->speed = 2;
	enemy->shot = false;
	enemy->dead = false;
}

void	get_enemy_coordinates(t_map *map, int rows, int coll)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (!enemy)
		return (free_map(map, "malloc error enemy", 1));
	if (map->enemy_count > 1)
		map->enemies = ft_realloc(map->enemies, sizeof(t_enemy *)
				* (map->enemy_count - 1), sizeof(t_enemy *) * map->enemy_count);
	if (!map->enemies)
		free_map(map, "error with enemies", 1);
	map->enemies[map->enemy_count - 1] = enemy;
	enemy->pos.x = coll * SCALE + 3 * (ESIZE / 2);
	enemy->pos.y = rows * SCALE + 3 * (ESIZE / 2);
	get_enemy_coordinates_aux(enemy);
	if (map->map[rows][coll] == 'O')
		enemy->type = OFFICER;
	else if (map->map[rows][coll] == 'B')
		enemy->type = BOSS;
	else if (map->map[rows][coll] == 'R')
		enemy->type = RAT;
	map->map[rows][coll] = '0';
}

void	invalid_characters_aux(t_map *map, int rows, int coll,
		bool *player_found)
{
	if (ft_strchr(PLAYER, map->map[rows][coll]))
	{
		if (*player_found)
			free_map(map, "There can only be 1 player", 1);
		get_player_coordinates(map, rows, coll);
		*player_found = true;
	}
	else if (ft_strchr(ENEMY, map->map[rows][coll]))
	{
		map->enemy_count++;
		get_enemy_coordinates(map, rows, coll);
	}
}

bool	invalid_characters(t_map *map)
{
	int		rows;
	int		coll;
	bool	player_found;

	rows = 0;
	player_found = false;
	while (rows < map->rows)
	{
		coll = 0;
		while (map->map[rows][coll])
		{
			invalid_characters_aux(map, rows, coll, &player_found);
			if (!ft_strchr(VALID_CHARS, map->map[rows][coll]))
				return (true);
			coll++;
		}
		if (map->cols < coll)
			map->cols = coll;
		rows++;
	}
	if (!player_found)
		free_map(map, "There is no player in this map", 1);
	fill_with_space(map);
	return (false);
}
