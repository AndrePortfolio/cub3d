/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:21:45 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/06/19 14:01:21 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

void	get_enemy_distance_aux(t_enemy_tools *e, t_raycaster *ray, t_game *game,
		int i)
{
	e->enemy_line_length = hypot(e->enemy[i]->right.x - e->enemy[i]->left.x,
			e->enemy[i]->right.y - e->enemy[i]->left.y);
	e->intersection_pos = hypot(e->intersection.x - e->enemy[i]->left.x,
			e->intersection.y - e->enemy[i]->left.y) / e->enemy_line_length;
	ray->enemy_type = e->enemy[i]->type;
	ray->enemy_id = i;
	ray->enemy = true;
	ray->distance_enemy = e->distance;
	ray->tex_x = e->intersection_pos
		* game->textures->enemy[ray->enemy_type][0].width;
}

void	get_enemy_distance(t_raycaster *ray, t_game *game)
{
	t_enemy_tools	e;

	init_enemy_tools(&e, game, ray);
	while (e.i < game->enemy_count)
	{
		if (lines_intersect(ray->start, e.ray_end, e.enemy[e.i],
				&e.intersection))
		{
			e.distance = hypot(ray->start.x - e.intersection.x, ray->start.y
					- e.intersection.y);
			if (e.distance < ray->distance_enemy)
				get_enemy_distance_aux(&e, ray, game, e.i);
		}
		e.i++;
	}
}

int	get_enemy_color(t_game *game, t_raycaster *ray, int tex_x, int tex_y)
{
	int			color;
	int			bpp;
	int			len;
	int			frame;
	t_textures	*t;

	color = 0;
	t = game->textures;
	frame = game->enemies[ray->enemy_id]->frame;
	bpp = t->enemy[ray->enemy_type][frame].bits_per_pixel;
	len = t->enemy[ray->enemy_type][frame].line_len;
	color = *(int *)&t->enemy[ray->enemy_type][frame].pixels_ptr[tex_x * (bpp
			/ 8) + (tex_y * len)];
	if (color == 6517885)
		return (-1);
	return (color);
}

void	draw_enemy(t_game *game, int x, t_raycaster *ray)
{
	t_drawenemy_tools	d;

	d.distance_factor = 1.0f / ray->distance_enemy;
	if (ray->enemy_type == OFFICER)
		d.enemy_scale = 5000;
	else if (ray->enemy_type == BOSS)
		d.enemy_scale = 8000;
	else
		d.enemy_scale = 10000;
	d.enemy_height = d.enemy_scale * d.distance_factor;
	d.bottom.y = HEIGHT * 0.5f + 8000 * d.distance_factor
		+ game->player->jump_height;
	d.top.y = d.bottom.y - 2 * d.enemy_height;
	d.tex_y = 0;
	d.step = (float)game->textures->enemy[ray->enemy_type][0].height
		/ (d.bottom.y - d.top.y);
	while (d.top.y < d.bottom.y)
	{
		d.color = get_enemy_color(game, ray, ray->tex_x, d.tex_y);
		if (d.color != -1)
			put_pixel_to_img(game, x, d.top.y, d.color);
		d.top.y++;
		d.tex_y += d.step;
	}
}

void	animate_sprites(t_game *game)
{
	int			i;
	static int	frame = 0;
	static int	counter = 0;

	i = 0;
	while (i < game->enemy_count)
	{
		if (game->enemies[i]->dead)
			game->enemies[i]->frame = 7;
		else if (!game->enemies[i]->shot)
			game->enemies[i]->frame = frame;
		else
			game->enemies[i]->frame = frame + 4;
		if (game->enemies[i]->frame == 7)
			game->enemies[i]->dead = true;
		i++;
	}
	if (++counter == ANIMATION_SPEED)
	{
		frame = (frame + 1) % 4;
		counter = 0;
	}
	move_sprites(game);
}
