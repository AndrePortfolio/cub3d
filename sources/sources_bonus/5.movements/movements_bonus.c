/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:48:49 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/18 11:23:11 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

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
	jumping(game->player);
	move_player(game, new_x, new_y);
}

void	move_player_aux(t_point_i wall_in, t_player *player, float new_x,
		float new_y)
{
	if (!wall_in.x && !wall_in.y)
	{
		player->pos.y = new_y;
		player->pos.x = new_x;
	}
	else if (!wall_in.x)
		player->pos.x = new_x;
	else if (!wall_in.y)
		player->pos.y = new_y;
}

void	move_player(t_game *game, float new_x, float new_y)
{
	t_player	*player;
	t_point_i	wall_in;

	player = game->player;
	wall_in.x = game->map->map[(int)(player->pos.y / SCALE)][(int)(new_x
			/ SCALE)] == WALL || game->map->map[(int)(player->pos.y + PSIZE)
		/ SCALE][((int)(new_x + PSIZE)) / SCALE] == WALL
		|| game->map->map[(int)(player->pos.y + PSIZE) / SCALE][(int)new_x
		/ SCALE] == WALL || game->map->map[(int)(player->pos.y)
		/ SCALE][((int)new_x + PSIZE) / SCALE] == WALL;
	wall_in.y = game->map->map[(int)(new_y / SCALE)][(int)(player->pos.x
			/ SCALE)] == WALL || game->map->map[(int)(new_y + PSIZE)
		/ SCALE][(int)(player->pos.x + PSIZE) / SCALE] == WALL
		|| game->map->map[(int)(new_y + PSIZE) / SCALE][(int)player->pos.x
		/ SCALE] == WALL || game->map->map[(int)(new_y)
		/ SCALE][((int)player->pos.x + PSIZE) / SCALE] == WALL;
	move_player_aux(wall_in, player, new_x, new_y);
}
