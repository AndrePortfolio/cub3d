/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:47:23 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/18 12:49:37 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

bool	flood_fill(t_map *map_array, char **map, int row, int col)
{
	if (row < 0 || col < 0 || row >= map_array->rows || col >= map_array->cols)
		return (false);
	if (map[row][col] == WALL || map[row][col] == VISITED)
		return (true);
	if (map[row][col] == '\0' || map[row][col] == ' ')
		return (false);
	map[row][col] = VISITED;
	if (!flood_fill(map_array, map, row + 1, col))
		return (false);
	if (!flood_fill(map_array, map, row, col + 1))
		return (false);
	if (!flood_fill(map_array, map, row - 1, col))
		return (false);
	if (!flood_fill(map_array, map, row, col - 1))
		return (false);
	return (true);
}

char	**copy_map(t_map *map)
{
	char	**map_copy;
	int		row;

	row = 0;
	map_copy = (char **)malloc(sizeof(char *) * (map->rows + 1));
	if (!map_copy)
		free_map(map, "Malloc error copy map\n", 1);
	while (row < map->rows)
	{
		map_copy[row] = ft_strdup(map->map[row]);
		row++;
	}
	map_copy[row] = NULL;
	return (map_copy);
}

bool	empty_left(char **map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == EMPTY)
			{
				return (true);
			}
			col++;
		}
		row++;
	}
	return (false);
}

bool	surrounded_by_walls(t_map *map)
{
	char	**map_copy;
	int		row;
	int		col;

	map_copy = copy_map(map);
	row = 0;
	col = 0;
	while (map_copy[row])
	{
		col = 0;
		while (map_copy[row][col])
		{
			if (map_copy[row][col] == EMPTY)
			{
				if (!flood_fill(map, map_copy, row, col))
					return (free_map_copy(map_copy), false);
			}
			col++;
		}
		row++;
	}
	if (empty_left(map_copy))
		return (free_map_copy(map_copy), false);
	return (free_map_copy(map_copy), true);
}
