/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:45:48 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/13 15:43:17 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_normal/cub3d.h"

void	prepate_to_move_player(t_player *p, float *new_x, float *new_y)
{
	if (p->up_down == UP)
	{
		*new_x = p->pos.x + (p->speed * (float)cos(p->p_angle));
		*new_y = p->pos.y + (p->speed * (float)sin(p->p_angle));
	}
	if (p->up_down == DOWN)
	{
		*new_x = p->pos.x + (p->speed * (float)cos(p->p_angle + PI));
		*new_y = p->pos.y + (p->speed * (float)sin(p->p_angle + PI));
	}
	if (p->left_right == LEFT)
	{
		*new_x = p->pos.x + (p->speed * (float)cos(p->p_angle - _05PI));
		*new_y = p->pos.y + (p->speed * (float)sin(p->p_angle - _05PI));
	}
	if (p->left_right == RIGHT)
	{
		*new_x = p->pos.x + (p->speed * (float)cos(p->p_angle + _05PI));
		*new_y = p->pos.y + (p->speed * (float)sin(p->p_angle + _05PI));
	}
}

void	check_movements(t_game *game)
{
	t_player	*player;
	float		new_x;
	float		new_y;

	player = game->player;
	new_x = player->pos.x;
	new_y = player->pos.y;
	prepate_to_move_player(player, &new_x, &new_y);
	rotate_player(player);
	move_player(game, new_x, new_y);
}

void	move_player(t_game *game, float nx, float ny)
{
	t_player	*p;
	char		**m;
	int			wall_x;
	int			wall_y;

	m = game->map->map;
	p = game->player;
	wall_x = m[(int)(p->pos.y / SCALE)][(int)(nx / SCALE)] == WALL
		|| m[(int)(p->pos.y + PSIZE) / SCALE][((int)(nx + PSIZE))
		/ SCALE] == WALL || m[(int)(p->pos.y + PSIZE) / SCALE][(int)nx
		/ SCALE] == WALL || m[(int)(p->pos.y) / SCALE][((int)nx + PSIZE)
		/ SCALE] == WALL;
	wall_y = m[(int)(ny / SCALE)][(int)(p->pos.x / SCALE)] == WALL || m[(int)(ny
			+ PSIZE) / SCALE][(int)(p->pos.x + PSIZE) / SCALE] == WALL
		|| m[(int)(ny + PSIZE) / SCALE][(int)p->pos.x / SCALE] == WALL
		|| m[(int)(ny) / SCALE][((int)p->pos.x + PSIZE) / SCALE] == WALL;
	if (!wall_x && !wall_y)
	{
		p->pos.y = ny;
		p->pos.x = nx;
	}
	else if (!wall_x)
		p->pos.x = nx;
	else if (!wall_y)
		p->pos.y = ny;
}

void	rotate_player(t_player *player)
{
	if (player->rot == LEFT)
	{
		player->p_angle -= (float)ROT_SPEED;
		if (player->p_angle < 0)
			player->p_angle += _2PI;
	}
	if (player->rot == RIGHT)
	{
		player->p_angle += (float)ROT_SPEED;
		if (player->p_angle > _2PI)
			player->p_angle -= _2PI;
	}
}
