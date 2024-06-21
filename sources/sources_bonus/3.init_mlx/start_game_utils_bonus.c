/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:56:00 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/06/19 12:46:23 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

void	map(t_game *game)
{
	t_map_tools	m;

	init_map_tools(game, &m);
	while (m.pixel.y < (HEIGHT - (HEIGHT / 5) + (HEIGHT / SCALE)) + (MINI_SCALE
			* MINI_ROWS))
	{
		m.pixel.x = (WIDTH - (WIDTH / 5) + (WIDTH / SCALE)) - ADJUST;
		m.tex.x = 0;
		while (m.pixel.x < (WIDTH - (WIDTH / 5) + (WIDTH / SCALE)) + (MINI_SCALE
				* MINI_COLS) + ADJUST)
		{
			m.color = get_map_color((int)m.tex.x, (int)m.tex.y, m.texture);
			if (!((m.color >> 24) & 0xFF))
				put_pixel_to_img(game, m.pixel.x, m.pixel.y, m.color);
			m.tex.x += m.scale.x;
			m.pixel.x++;
		}
		m.tex.y += m.scale.y;
		m.pixel.y++;
	}
}

int	render(t_game *game)
{
	t_raycaster	ray;

	if (game->is_player_dead)
		return (0);
	check_movements(game);
	get_enemy_positions(game);
	animate_sprites(game);
	raycast(game, &ray);
	render_weapon(game);
	map(game);
	minimap(game, &ray);
	aim(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	return (0);
}

void	player_dead(t_game *game)
{
	game->is_player_dead = true;
}
