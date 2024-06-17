/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rays_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:48:40 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/13 15:44:46 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

void	raycast_2d(t_game *game, t_raycaster *ray, t_minimap mini)
{
	t_player	*player;
	float		angle;

	player = game->player;
	angle = player->p_angle - (PLAYER_VISION / 2);
	while (angle < player->p_angle + (PLAYER_VISION / 2))
	{
		cast_2d_ray(game, angle, ray, mini);
		angle += (PLAYER_VISION / WIDTH);
	}
}

void	cast_2d_ray_aux(t_raycaster *ray, int *visited)
{
	if (ray->ray_len.x < ray->ray_len.y)
	{
		*visited = 1;
		ray->len = ray->ray_len.x;
		ray->ray_len.x += ray->scalingf.x * MINI_SCALE;
		ray->map_loc.x += ray->map_step.x;
	}
	else
	{
		*visited = 2;
		ray->len = ray->ray_len.y;
		ray->ray_len.y += ray->scalingf.y * MINI_SCALE;
		ray->map_loc.y += ray->map_step.y;
	}
}

void	cast_2d_ray(t_game *game, float angle, t_raycaster *ray, t_minimap mini)
{
	t_player	*player;
	int			visited;

	visited = 0;
	player = game->player;
	init_2d_ray(ray, player, angle);
	while (!ray->wall)
	{
		cast_2d_ray_aux(ray, &visited);
		if (game->map->map[ray->map_loc.y][ray->map_loc.x] == WALL)
			check_direction(game, ray, visited);
	}
	adjust_raylen(ray, angle, mini, player);
	draw_ray(game, player, ray, mini);
}

void	init_2d_ray_aux(t_raycaster *ray)
{
	if (ray->dir.y < NORTH_)
	{
		ray->map_step.y = -1;
		ray->ray_len.y = (ray->start.y - ray->map_loc.y * MINI_SCALE)
			* ray->scalingf.y;
	}
	else
	{
		ray->map_step.y = 1;
		ray->ray_len.y = ((ray->map_loc.y + 1) * MINI_SCALE - ray->start.y)
			* ray->scalingf.y;
	}
	if (ray->dir.x < WEST_)
	{
		ray->map_step.x = -1;
		ray->ray_len.x = (ray->start.x - ray->map_loc.x * MINI_SCALE)
			* ray->scalingf.x;
	}
	else
	{
		ray->map_step.x = 1;
		ray->ray_len.x = ((ray->map_loc.x + 1) * MINI_SCALE - ray->start.x)
			* ray->scalingf.x;
	}
}

void	init_2d_ray(t_raycaster *ray, t_player *player, float angle)
{
	ray->dir.x = cos(angle);
	ray->dir.y = sin(angle);
	ray->scalingf.x = sqrt(1 + (ray->dir.y / ray->dir.x) * (ray->dir.y
				/ ray->dir.x));
	ray->scalingf.y = sqrt(1 + (ray->dir.x / ray->dir.y) * (ray->dir.x
				/ ray->dir.y));
	ray->map_loc.x = (int)player->pos.x / SCALE;
	ray->map_loc.y = (int)player->pos.y / SCALE;
	ray->start.x = (player->pos.x + PCENTER) / 2;
	ray->start.y = (player->pos.y + PCENTER) / 2;
	init_2d_ray_aux(ray);
	ray->wall = false;
	ray->len = 0;
}
