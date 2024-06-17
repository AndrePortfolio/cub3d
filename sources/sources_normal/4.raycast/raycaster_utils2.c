/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:52:58 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/13 15:43:17 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_normal/cub3d.h"

void	closer_distance(t_raycaster *ray, int *visited)
{
	if (ray->ray_len.x < ray->ray_len.y)
	{
		*visited = 1;
		ray->len = ray->ray_len.x;
		ray->ray_len.x += ray->scalingf.x * SCALE;
		ray->map_loc.x += ray->map_step.x;
	}
	else
	{
		*visited = 2;
		ray->len = ray->ray_len.y;
		ray->ray_len.y += ray->scalingf.y * SCALE;
		ray->map_loc.y += ray->map_step.y;
	}
}

void	check_dir(t_raycaster *ray)
{
	if (ray->dir.y < NORTH_)
	{
		ray->map_step.y = -1;
		ray->ray_len.y = (ray->start.y - ray->map_loc.y * SCALE)
			* ray->scalingf.y;
	}
	else
	{
		ray->map_step.y = 1;
		ray->ray_len.y = ((ray->map_loc.y + 1) * SCALE - ray->start.y)
			* ray->scalingf.y;
	}
	if (ray->dir.x < WEST_)
	{
		ray->map_step.x = -1;
		ray->ray_len.x = (ray->start.x - ray->map_loc.x * SCALE)
			* ray->scalingf.x;
	}
	else
	{
		ray->map_step.x = 1;
		ray->ray_len.x = ((ray->map_loc.x + 1) * SCALE - ray->start.x)
			* ray->scalingf.x;
	}
}
