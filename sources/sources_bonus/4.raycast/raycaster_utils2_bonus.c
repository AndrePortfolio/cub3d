/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:28:47 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/06/19 12:39:29 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

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

void	check_direction(t_game *game, t_raycaster *ray, int visited)
{
	if (visited == 2)
	{
		if (ray->dir.y < NORTH_)
			game->dir = N_;
		else
			game->dir = S_;
	}
	else
	{
		if (ray->dir.x < WEST_)
			game->dir = W_;
		else
			game->dir = E_;
	}
	ray->wall = true;
}

float	cast_ray(t_raycaster *ray, t_game *game, float angle)
{
	t_player	*player;
	int			visited;

	visited = 0;
	player = game->player;
	init_ray(ray, player, angle);
	while (!ray->wall)
	{
		closer_distance(ray, &visited);
		if (game->map->map[ray->map_loc.y][ray->map_loc.x] == WALL)
			check_direction(game, ray, visited);
	}
	game->fraction_x = fmod((ray->start.x + ray->dir.x * ray->len),
			(float)SCALE) / (float)SCALE;
	game->fraction_y = fmod((ray->start.y + ray->dir.y * ray->len),
			(float)SCALE) / (float)SCALE;
	return (ray->len);
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

void	init_ray(t_raycaster *ray, t_player *player, float angle)
{
	ray->dir.x = cos(angle);
	ray->dir.y = sin(angle);
	ray->scalingf.x = sqrt(1 + (ray->dir.y / ray->dir.x) * (ray->dir.y
				/ ray->dir.x));
	ray->scalingf.y = sqrt(1 + (ray->dir.x / ray->dir.y) * (ray->dir.x
				/ ray->dir.y));
	ray->map_loc.x = (int)(player->pos.x + PCENTER) / SCALE;
	ray->map_loc.y = (int)(player->pos.y + PCENTER) / SCALE;
	ray->start.x = player->pos.x + PCENTER;
	ray->start.y = player->pos.y + PCENTER;
	ray->wall = false;
	check_dir(ray);
	ray->len = 0;
	ray->enemy = false;
	ray->enemy_type = -1;
	ray->distance_enemy = (float)INT_MAX;
	ray->tex_x = 0;
	ray->enemy_id = 0;
}
