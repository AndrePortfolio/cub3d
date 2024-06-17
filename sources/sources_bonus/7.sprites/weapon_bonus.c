/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:49:21 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/13 15:44:46 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

int	get_weapon_color(t_game *game, int tex_x, int tex_y, int frame)
{
	int			color;
	int			bpp;
	int			len;
	int			w_type;
	t_textures	*t;

	color = 0;
	w_type = game->player->weapon;
	t = game->textures;
	bpp = t->weapon[w_type][frame].bits_per_pixel;
	len = t->weapon[w_type][frame].line_len;
	color = *(int *)&t->weapon[w_type][frame].pixels_ptr[tex_x * (bpp / 8)
		+ (tex_y * len)];
	if (color == 9961608 || color == 33023)
		return (-1);
	return (color);
}

void	init_weapon_tools(t_game *game, t_weapon_tools *w)
{
	w->scale = 8;
	w->type = game->player->weapon;
	w->color = 0;
	w->pixel.x = 0;
	w->pixel.y = 0;
}

void	draw_weapon(t_game *game, int frame)
{
	t_weapon_tools	w;

	t_img(*weapon)[5];
	init_weapon_tools(game, &w);
	weapon = game->textures->weapon;
	w.pixel.y = HEIGHT - weapon[w.type][frame].height * w.scale;
	w.tex.y = 0;
	while (w.pixel.y < HEIGHT)
	{
		w.pixel.x = (WIDTH / 2) - (weapon[w.type][frame].width * w.scale / 2);
		w.tex.x = 0;
		while (w.pixel.x < (WIDTH / 2) + (weapon[w.type][frame].width * w.scale
			/ 2))
		{
			w.color = get_weapon_color(game, w.tex.x, w.tex.y, frame);
			if (w.color != -1)
				put_pixel_to_img(game, w.pixel.x, w.pixel.y, w.color);
			w.pixel.x++;
			if (w.pixel.x % w.scale == 0)
				w.tex.x++;
		}
		w.pixel.y++;
		if (w.pixel.y % w.scale == 0)
			w.tex.y++;
	}
}

void	render_weapon(t_game *game)
{
	int	*frame;

	frame = &game->player->shooting;
	if (*frame)
	{
		if (*frame < SHOOT_SPEED * 5)
		{
			draw_weapon(game, *frame / SHOOT_SPEED);
			(*frame)++;
		}
		else
			*frame = 0;
	}
	else
		draw_weapon(game, *frame);
}
