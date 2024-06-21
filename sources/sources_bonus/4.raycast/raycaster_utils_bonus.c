/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:48:58 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/19 14:12:40 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

void	draw_textures(t_game *game, int x, int start_y, int end_y)
{
	int		temp;
	int		color;
	float	tex_y;
	float	tex_x;
	float	step;

	temp = 0;
	if (start_y > end_y)
	{
		temp = start_y;
		start_y = end_y;
		end_y = temp;
	}
	tex_y = 0;
	tex_x = game->textures->north.width * (game->fraction_x + game->fraction_y);
	step = (float)game->textures->north.height / (end_y - start_y);
	while (start_y <= end_y)
	{
		color = get_texture_color(game, tex_x, tex_y);
		put_pixel_to_img(game, x, start_y, color);
		start_y++;
		tex_y += step;
	}
}

int	get_texture_color(t_game *game, int tex_x, int tex_y)
{
	int			color;
	int			bpp;
	int			len;
	t_textures	*t;

	color = 0;
	t = game->textures;
	bpp = t->north.bits_per_pixel;
	len = t->north.line_len;
	if (game->dir == N_)
		color = *(int *)&t->north.pixels_ptr[tex_x * (bpp / 8) + (tex_y * len)];
	else if (game->dir == S_)
		color = *(int *)&t->south.pixels_ptr[tex_x * (bpp / 8) + (tex_y * len)];
	else if (game->dir == W_)
		color = *(int *)&t->west.pixels_ptr[tex_x * (bpp / 8) + (tex_y * len)];
	else
		color = *(int *)&t->east.pixels_ptr[tex_x * (bpp / 8) + (tex_y * len)];
	return (color);
}

void	draw_vline(t_game *game, int x, int start_y, int end_y)
{
	int	temp;
	int	color;

	if (end_y == HEIGHT)
		color = game->f_color;
	else
		color = game->c_color;
	temp = 0;
	if (start_y > end_y)
	{
		temp = start_y;
		start_y = end_y;
		end_y = temp;
	}
	while (true)
	{
		put_pixel_to_img(game, x, start_y, color);
		if (start_y == end_y)
			break ;
		start_y++;
	}
}

void	put_pixel_to_img(t_game *game, int x, int y, int color)
{
	int	offset;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		offset = (y * game->img.line_len) + (x * (game->img.bits_per_pixel
					/ 8));
		*(unsigned int *)(game->img.pixels_ptr + offset) = color;
	}
}

void	draw(t_game *game, int x, t_ray_tools *r)
{
	draw_textures(game, x, r->top.y, r->bottom.y);
	draw_floor(game, x, r->bottom.y, HEIGHT);
	draw_ceiling(game, x, 0, r->top.y);
}
