/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:49:15 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/13 15:44:46 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

void	start_game(t_map *map)
{
	t_game		game;
	t_player	player;
	t_textures	textures;

	init_mlx(&game, &textures, &player, map);
	mlx_loop_hook(game.mlx, &render, &game);
	mlx_loop(game.mlx);
}

int	get_aim_color(int tex_x, int tex_y, t_textures *texture)
{
	int	color;
	int	bpp;
	int	len;

	bpp = texture->aim.bits_per_pixel;
	len = texture->aim.line_len;
	if (tex_x < 0 || tex_x >= texture->aim.width || tex_y < 0
		|| tex_y >= texture->aim.height)
		return (0);
	color = *(int *)&texture->aim.pixels_ptr[tex_x * (bpp / 8) + (tex_y * len)];
	return (color);
}

void	aim(t_game *game)
{
	t_textures	*texture;
	t_point		tex;
	int			color;
	int			x;
	int			y;

	texture = game->textures;
	y = (HEIGHT / 2) - (HEIGHT / 20);
	while (y < (HEIGHT / 2) + (HEIGHT / 20))
	{
		x = (WIDTH / 2) - (WIDTH / 20);
		while (x < (WIDTH / 2) + (WIDTH / 20))
		{
			tex.x = x - (WIDTH / 2) + (texture->aim.width / 2);
			tex.y = y - (HEIGHT / 2) + (texture->aim.height / 2);
			color = get_aim_color(tex.x, tex.y, texture);
			if (!((color >> 24) & 0xFF))
				put_pixel_to_img(game, x, y, color);
			x++;
		}
		y++;
	}
}

int	get_map_color(int tex_x, int tex_y, t_textures *texture)
{
	int	color;
	int	bpp;
	int	len;

	bpp = texture->map.bits_per_pixel;
	len = texture->map.line_len;
	if (tex_x < 0 || tex_x >= texture->map.width || tex_y < 0
		|| tex_y >= texture->map.height)
		return (0);
	color = *(int *)&texture->map.pixels_ptr[tex_x * (bpp / 8) + (tex_y * len)];
	return (color);
}

void	init_map_tools(t_game *game, t_map_tools *m)
{
	m->texture = game->textures;
	m->mini_width = (WIDTH - (WIDTH / 5) + (WIDTH / SCALE)) + (MINI_SCALE
			* MINI_COLS) - (WIDTH - (WIDTH / 5) + (WIDTH / SCALE)) + 20;
	m->mini_height = (HEIGHT - (HEIGHT / 5) + (HEIGHT / SCALE)) + (MINI_SCALE
			* MINI_ROWS) - (HEIGHT - (HEIGHT / 5) + (HEIGHT / SCALE)) - 10 + 30;
	m->scale.x = (float)m->texture->map.width / m->mini_width;
	m->scale.y = (float)m->texture->map.height / m->mini_height;
	m->pixel.y = (HEIGHT - (HEIGHT / 5) + (HEIGHT / SCALE)) - 10 - 10;
	m->tex.y = 0;
}
