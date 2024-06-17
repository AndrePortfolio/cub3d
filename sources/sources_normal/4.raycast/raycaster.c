/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:45:54 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/13 15:43:17 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_normal/cub3d.h"

void	init_ray_tools(t_ray_tools *r)
{
	r->adjusted = 0;
	r->angle = 0;
	r->distance = 0;
	r->top.x = 0;
	r->top.y = 0;
	r->bottom.x = 0;
	r->bottom.y = 0;
	r->wall_height = 0;
}

void	raycast(t_game *game, t_raycaster *ray)
{
	t_player	*player;
	t_ray_tools	r;
	int			x;

	init_ray_tools(&r);
	player = game->player;
	r.angle = player->p_angle - (PLAYER_VISION / 2);
	x = 0;
	while (r.angle < player->p_angle + (PLAYER_VISION / 2))
	{
		r.distance = cast_ray(game, r.angle, ray);
		r.adjusted = r.distance * cos(r.angle - player->p_angle);
		r.wall_height = (WALL_SCALE / r.adjusted);
		r.top.y = (HEIGHT / 2) - r.wall_height;
		r.bottom.y = (HEIGHT / 2) + r.wall_height;
		draw_textures(game, x, r.top.y, r.bottom.y);
		draw_vline(game, x, r.bottom.y, HEIGHT);
		draw_vline(game, x, 0, r.top.y);
		r.angle += (PLAYER_VISION / WIDTH);
		x++;
	}
}

float	cast_ray(t_game *game, float angle, t_raycaster *ray)
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
	check_dir(ray);
	ray->wall = false;
	ray->len = 0;
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
