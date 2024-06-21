/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:19:06 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/06/19 14:08:25 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

void	move_sprites_aux(t_sprite_tools *s, int i)
{
	if (!s->wall_in.x && !s->wall_in.y && !s->close_to_others)
	{
		s->enemy[i]->pos.y = s->new_pos.y;
		s->enemy[i]->pos.x = s->new_pos.x;
	}
	else if (!s->wall_in.x && !s->close_to_others)
		s->enemy[i]->pos.x = s->new_pos.x;
	else if (!s->wall_in.y && !s->close_to_others)
		s->enemy[i]->pos.y = s->new_pos.y;
	s->enemy[i]->left.x = s->enemy[i]->pos.x - s->enemy[i]->dir_vec.y
		* s->enemy[i]->size / 2;
	s->enemy[i]->left.y = s->enemy[i]->pos.y + s->enemy[i]->dir_vec.x
		* s->enemy[i]->size / 2;
	s->enemy[i]->right.x = s->enemy[i]->pos.x + s->enemy[i]->dir_vec.y
		* s->enemy[i]->size / 2;
	s->enemy[i]->right.y = s->enemy[i]->pos.y - s->enemy[i]->dir_vec.x
		* s->enemy[i]->size / 2;
}

void	init_sprite_tools(t_sprite_tools *s, t_game *game)
{
	s->map = game->map->map;
	s->enemy = game->enemies;
	s->new_pos.x = 0;
	s->new_pos.y = 0;
	s->wall_in.x = 0;
	s->wall_in.y = 0;
	s->close_to_others = false;
}

void	get_wall_in(t_sprite_tools *s, int i)
{
	s->wall_in.x = s->map[(int)(s->enemy[i]->pos.y / SCALE)][(int)(s->new_pos.x
			/ SCALE)] == WALL || s->map[(int)(s->enemy[i]->pos.y
			+ s->enemy[i]->size) / SCALE][((int)(s->new_pos.x
				+ s->enemy[i]->size)) / SCALE] == WALL
		|| s->map[(int)(s->enemy[i]->pos.y + s->enemy[i]->size) / SCALE]
	[(int)s->new_pos.x / SCALE] == WALL || s->map[(int)(s->enemy[i]->pos.y)
		/ SCALE][((int)s->new_pos.x + s->enemy[i]->size) / SCALE] == WALL;
	s->wall_in.y = s->map[(int)(s->new_pos.y / SCALE)][(int)(s->enemy[i]->pos.x
			/ SCALE)] == WALL || s->map[(int)(s->new_pos.y + s->enemy[i]->size)
		/ SCALE][(int)(s->enemy[i]->pos.x + s->enemy[i]->size) / SCALE] == WALL
		|| s->map[(int)(s->new_pos.y + s->enemy[i]->size) / SCALE]
	[(int)s->enemy[i]->pos.x / SCALE] == WALL || s->map[(int)(s->new_pos.y)
		/ SCALE][((int)s->enemy[i]->pos.x + s->enemy[i]->size) / SCALE] == WALL;
}

bool	distance_to_others(t_game *game, t_sprite_tools *s, int id)
{
	int	i;

	if (distance(s->new_pos.x, s->new_pos.y, game->player->pos.x,
			game->player->pos.y) < MIN_DISTANCE)
		return (true);
	i = 0;
	while (i < game->enemy_count)
	{
		if (i != id)
		{
			if (distance(s->new_pos.x, s->new_pos.y, game->enemies[i]->pos.x,
					game->enemies[i]->pos.y) < MIN_DISTANCE)
				return (true);
		}
		i++;
	}
	return (false);
}

void	move_sprites(t_game *game)
{
	t_sprite_tools	s;
	int				i;

	init_sprite_tools(&s, game);
	i = 0;
	while (i < game->enemy_count)
	{
		if (!s.enemy[i]->dead)
		{
			s.new_pos.x = s.enemy[i]->pos.x + (s.enemy[i]->speed
					* s.enemy[i]->dir_vec.x);
			s.new_pos.y = s.enemy[i]->pos.y + (s.enemy[i]->speed
					* s.enemy[i]->dir_vec.y);
			if (distance_to_others(game, &s, i))
				s.close_to_others = true;
			get_wall_in(&s, i);
			move_sprites_aux(&s, i);
		}
		i++;
	}
}
