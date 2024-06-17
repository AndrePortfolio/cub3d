/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rays_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:04:14 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/13 15:44:46 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

void	adjust_raylen_aux(t_player *player, t_minimap mini, t_point center,
		t_point *max_dist)
{
	if ((player->pos.x <= mini.hori_vision)
		&& (player->pos.y <= mini.vert_vision))
	{
		max_dist->y = (MINI_ROWS * MINI_SCALE) / 2 + fabs(center.y
				- mini.player.y);
		max_dist->x = (MINI_COLS * MINI_SCALE) / 2 + fabs(center.x
				- mini.player.x);
	}
	else if (player->pos.y <= mini.vert_vision)
	{
		max_dist->y = (MINI_ROWS * MINI_SCALE) / 2 + fabs(center.y
				- mini.player.y);
		max_dist->x = (MINI_COLS * MINI_SCALE) / 2;
	}
	else if (player->pos.x <= mini.hori_vision)
	{
		max_dist->y = (MINI_ROWS * MINI_SCALE) / 2;
		max_dist->x = (MINI_COLS * MINI_SCALE) / 2 + fabs(center.x
				- mini.player.x);
	}
	else
	{
		max_dist->y = (MINI_ROWS * MINI_SCALE) / 2;
		max_dist->x = (MINI_COLS * MINI_SCALE) / 2;
	}
}

void	adjust_raylen(t_raycaster *ray, float angle, t_minimap mini,
		t_player *player)
{
	t_point	max_dist;
	t_point	true_max;
	t_point	center;

	center.y = ((HEIGHT - (HEIGHT / 5) + (HEIGHT / SCALE)) + ((MINI_SCALE * 5)
				/ 2) - MINI_PCENTER);
	center.x = ((WIDTH - (WIDTH / 5) + (WIDTH / SCALE)) + ((MINI_SCALE * 7) / 2)
			- MINI_PCENTER);
	mini.player.x = ((WIDTH - (WIDTH / 5) + (WIDTH / SCALE)) + (player->pos.x
				/ 2));
	mini.player.y = ((HEIGHT - (HEIGHT / 5) + (HEIGHT / SCALE)) + (player->pos.y
				/ 2));
	adjust_raylen_aux(player, mini, center, &max_dist);
	true_max.y = fabs(max_dist.y / cos(_15PI - angle));
	true_max.x = fabs(max_dist.x / cos(angle - PI));
	if (true_max.x > true_max.y && ray->len > true_max.y)
		ray->len = true_max.y;
	else if (true_max.x < true_max.y && ray->len > true_max.x)
		ray->len = true_max.x;
}

void	draw_ray(t_game *game, t_player *player, t_raycaster *ray,
		t_minimap mini)
{
	t_point		close_to_b;
	t_point		centered;
	t_point_i	start;
	t_point_i	end;

	close_to_b.x = (((WIDTH - (WIDTH / 5) + (WIDTH / SCALE)) + (player->pos.x
					/ 2)) + MINI_PCENTER);
	close_to_b.y = (((HEIGHT - (HEIGHT / 5) + (HEIGHT / SCALE)) + (player->pos.y
					/ 2)) + MINI_PCENTER);
	centered.x = (((WIDTH - (WIDTH / 5) + (WIDTH / SCALE)) + ((MINI_SCALE * 7)
					/ 2) - MINI_PCENTER) + MINI_PCENTER);
	centered.y = (((HEIGHT - (HEIGHT / 5) + (HEIGHT / SCALE)) + ((MINI_SCALE
						* 5) / 2) - MINI_PCENTER) + MINI_PCENTER);
	if ((player->pos.x <= mini.hori_vision)
		&& (player->pos.y <= mini.vert_vision))
		draw_ray_aux1(&start, &end, close_to_b);
	else if (player->pos.y <= mini.vert_vision)
		draw_ray_aux2(&start, &end, close_to_b, centered);
	else if (player->pos.x <= mini.hori_vision)
		draw_ray_aux3(&start, &end, close_to_b, centered);
	else
		draw_ray_aux4(&start, &end, centered);
	end.x += (ray->dir.x * ray->len);
	end.y += (ray->dir.y * ray->len);
	draw_line(game, start, end);
}
