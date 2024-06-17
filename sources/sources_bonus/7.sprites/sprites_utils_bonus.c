/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:19:06 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/06/13 15:44:46 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

float	distance(float x1, float y1, float x2, float y2)
{
	float	dx;
	float	dy;

	dx = x2 - x1;
	dy = y2 - y1;
	return (sqrtf(dx * dx + dy * dy));
}

void	move_sprites_aux(t_point wall_in, t_enemy **enemy, t_point new_pos,
		int i)
{
	if (!wall_in.x && !wall_in.y)
	{
		enemy[i]->pos.y = new_pos.y;
		enemy[i]->pos.x = new_pos.x;
	}
	else if (!wall_in.x)
		enemy[i]->pos.x = new_pos.x;
	else if (!wall_in.y)
		enemy[i]->pos.y = new_pos.y;
	enemy[i]->left.x = enemy[i]->pos.x - enemy[i]->dir_vec.y * ESIZE / 2;
	enemy[i]->left.y = enemy[i]->pos.y + enemy[i]->dir_vec.x * ESIZE / 2;
	enemy[i]->right.x = enemy[i]->pos.x + enemy[i]->dir_vec.y * ESIZE / 2;
	enemy[i]->right.y = enemy[i]->pos.y - enemy[i]->dir_vec.x * ESIZE / 2;
}

void	init_sprite_tools(t_sprite_tools *s, t_game *game)
{
	s->map = game->map->map;
	s->enemy = game->enemies;
	s->new_pos.x = 0;
	s->new_pos.y = 0;
	s->wall_in.x = 0;
	s->wall_in.y = 0;
}

void	get_wall_in(t_sprite_tools *s, int i)
{
	s->wall_in.x = s->map[(int)(s->enemy[i]->pos.y / SCALE)][(int)(s->new_pos.x
			/ SCALE)] == WALL || s->map[(int)(s->enemy[i]->pos.y + PSIZE)
		/ SCALE][((int)(s->new_pos.x + PSIZE)) / SCALE] == WALL
		|| s->map[(int)(s->enemy[i]->pos.y + PSIZE) / SCALE][(int)s->new_pos.x
		/ SCALE] == WALL || s->map[(int)(s->enemy[i]->pos.y)
		/ SCALE][((int)s->new_pos.x + PSIZE) / SCALE] == WALL;
	s->wall_in.y = s->map[(int)(s->new_pos.y / SCALE)][(int)(s->enemy[i]->pos.x
			/ SCALE)] == WALL || s->map[(int)(s->new_pos.y + PSIZE)
		/ SCALE][(int)(s->enemy[i]->pos.x + PSIZE) / SCALE] == WALL
		|| s->map[(int)(s->new_pos.y + PSIZE) / SCALE][(int)s->enemy[i]->pos.x
		/ SCALE] == WALL || s->map[(int)(s->new_pos.y)
		/ SCALE][((int)s->enemy[i]->pos.x + PSIZE) / SCALE] == WALL;
}

void	move_sprites(t_game *game)
{
	t_sprite_tools	s;
	int				i;

	init_sprite_tools(&s, game);
	i = 0;
	while (i < game->enemy_count)
	{
		s.new_pos.x = s.enemy[i]->pos.x + (s.enemy[i]->speed
				* s.enemy[i]->dir_vec.x);
		s.new_pos.y = s.enemy[i]->pos.y + (s.enemy[i]->speed
				* s.enemy[i]->dir_vec.y);
		if (distance(s.new_pos.x, s.new_pos.y, game->player->pos.x,
				game->player->pos.y) < 10)
			return (player_dead(game));
		get_wall_in(&s, i);
		move_sprites_aux(s.wall_in, s.enemy, s.new_pos, i);
		i++;
	}
}
