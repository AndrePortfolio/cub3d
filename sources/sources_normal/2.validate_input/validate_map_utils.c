/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:44:50 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/18 11:06:08 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_normal/cub3d.h"

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
