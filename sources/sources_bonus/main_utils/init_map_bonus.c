/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:49:31 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/20 10:44:16 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

float	distance(float x1, float y1, float x2, float y2)
{
	float	dx;
	float	dy;

	dx = x2 - x1;
	dy = y2 - y1;
	return (sqrtf(dx * dx + dy * dy));
}

void	init_map(t_map *map)
{
	if (map == NULL)
		return ;
	map->map = NULL;
	map->rows = 0;
	map->fd = 0;
	map->player.x = 0;
	map->player.y = 0;
	map->player_dir = 0;
	map->cols = 0;
	map->no_texture = NULL;
	map->so_texture = NULL;
	map->we_texture = NULL;
	map->ea_texture = NULL;
	map->f_color.red = -1;
	map->f_color.green = -1;
	map->f_color.blue = -1;
	map->c_color.red = -1;
	map->c_color.green = -1;
	map->c_color.blue = -1;
	map->enemy_count = 0;
	map->enemies = malloc(sizeof(t_enemy *));
	if (!map->enemies)
		error_message(map, "Malloc error enemies");
}
