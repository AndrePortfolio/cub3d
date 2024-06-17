/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:44:44 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/13 15:43:17 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_normal/cub3d.h"

void	remove_extra_rows(t_map *map, int rows, char **temp)
{
	int	coll;
	int	rows_before;

	if (rows == 0)
		error_message("Empty map");
	rows_before = rows;
	while (rows > 0)
	{
		coll = 0;
		while (ft_isspace(map->map[rows - 1][coll]))
			coll++;
		if (map->map[rows - 1][coll] == '\0')
			free(map->map[rows - 1]);
		else
			break ;
		rows--;
	}
	temp = ft_realloc(map->map, sizeof(char *) * (rows_before), sizeof(char *)
			* (rows + 1));
	if (!temp)
		free_map(map, "Memory allocation failed", 1);
	map->rows = rows;
	map->map = temp;
	map->map[rows] = NULL;
}
