/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:19:08 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/13 15:44:46 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

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

void	rotate_player(t_player *player)
{
	if (player->rot == LEFT)
	{
		player->p_angle -= ROT_SPEED;
		if (player->p_angle < 0)
			player->p_angle += 2 * PI;
	}
	if (player->rot == RIGHT)
	{
		player->p_angle += ROT_SPEED;
		if (player->p_angle > 2 * PI)
			player->p_angle -= 2 * PI;
	}
}

void	jumping(t_player *player)
{
	float	jump_progress;
	float	jump_speed;
	float	fall_progress;
	float	fall_speed;

	if (player->jumping && !player->jump_peak)
	{
		jump_progress = player->jump_height / (float)MAX_JUMP_HEIGHT;
		jump_speed = MAX_JUMP_SPEED * (1.0 - jump_progress);
		player->jump_height += jump_speed;
		if (player->jump_height >= MAX_JUMP_HEIGHT || jump_speed < 0.5)
			player->jump_peak = true;
	}
	else if (player->jump_peak || !player->jumping)
	{
		fall_progress = 1.0 - (player->jump_height / (float)MAX_JUMP_HEIGHT);
		fall_speed = MAX_JUMP_SPEED * sqrt(fall_progress);
		player->jump_height -= fall_speed;
		if (player->jump_height <= 0)
		{
			player->jump_height = 0;
			player->jumping = false;
			player->jump_peak = false;
		}
	}
}
