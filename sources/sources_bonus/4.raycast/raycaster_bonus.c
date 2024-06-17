/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:48:54 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/13 15:44:46 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

int	get_fc_color(t_game *game, int tex_x, int tex_y, bool floor_ceiling)
{
	int			color;
	int			bpp;
	int			len;
	t_textures	*t;

	color = 0;
	t = game->textures;
	if (tex_y >= 0 && tex_y < HEIGHT + 110)
	{
		if (!floor_ceiling)
		{
			bpp = t->ground.bits_per_pixel;
			len = t->ground.line_len;
			color = *(int *)&t->ground.pixels_ptr[tex_x * (bpp / 8) + (tex_y
					* len)];
		}
		else
		{
			bpp = t->sky.bits_per_pixel;
			len = t->sky.line_len;
			color = *(int *)&t->sky.pixels_ptr[tex_x * (bpp / 8) + (tex_y
					* len)];
		}
	}
	return (color);
}

void	draw_ceiling(t_game *game, int x, int bottom, int top)
{
	int		color;
	int		temp;
	float	tex_y;
	float	tex_x;

	if (bottom > top)
	{
		temp = bottom;
		bottom = top;
		top = temp;
	}
	tex_x = (float)x / WIDTH * game->textures->sky.width;
	while (bottom <= top)
	{
		tex_y = (float)bottom / HEIGHT * game->textures->sky.height;
		color = get_fc_color(game, (int)tex_x, (int)tex_y, true);
		put_pixel_to_img(game, x, bottom, color);
		bottom++;
	}
}

void	draw_floor(t_game *game, int x, int bottom, int top)
{
	int		color;
	int		temp;
	float	tex_y;
	float	tex_x;

	if (bottom > top)
	{
		temp = bottom;
		bottom = top;
		top = temp;
	}
	tex_x = (float)x / WIDTH * game->textures->ground.width;
	while (bottom <= top)
	{
		tex_y = (float)bottom / HEIGHT * game->textures->ground.height;
		color = get_fc_color(game, (int)tex_x, (int)tex_y, false);
		put_pixel_to_img(game, x, bottom, color);
		bottom++;
	}
}

void	init_ray_tools(t_ray_tools *r, t_game *game)
{
	r->player = game->player;
	r->angle = r->player->p_angle - (PLAYER_VISION / 2);
	r->distance = 0;
	r->adjusted = 0;
	r->bottom.x = 0;
	r->top.y = 0;
	r->wall_height = 0;
}

void	raycast(t_game *game, t_raycaster *ray)
{
	t_ray_tools	r;
	int			x;

	init_ray_tools(&r, game);
	x = 0;
	while (r.angle < r.player->p_angle + (PLAYER_VISION / 2))
	{
		r.distance = cast_ray(ray, game, r.angle);
		r.adjusted = r.distance * cos(r.angle - r.player->p_angle);
		r.wall_height = (WALL_SCALE / r.adjusted);
		r.top.y = (HEIGHT / 2) - r.wall_height + r.player->jump_height;
		r.bottom.y = (HEIGHT / 2) + r.wall_height + r.player->jump_height;
		draw_textures(game, x, r.top.y, r.bottom.y);
		draw_floor(game, x, r.bottom.y, HEIGHT);
		draw_ceiling(game, x, 0, r.top.y);
		get_enemy_distance(ray, game);
		if (ray->enemy)
		{
			ray->distance_enemy *= cos(r.angle - r.player->p_angle);
			draw_enemy(game, x, ray);
		}
		r.angle += (PLAYER_VISION / WIDTH);
		x++;
	}
}
