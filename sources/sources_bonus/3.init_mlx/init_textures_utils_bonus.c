/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:19:28 by btoksoez          #+#    #+#             */
/*   Updated: 2024/06/19 14:19:42 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

void	init_textures_rat(t_game *game, t_textures *textures)
{
	init_texture(game, &textures->enemy[2][0],
		"./assets/textures/rat/rat1.xpm");
	init_texture(game, &textures->enemy[2][1],
		"./assets/textures/rat/rat2.xpm");
	init_texture(game, &textures->enemy[2][2],
		"./assets/textures/rat/rat3.xpm");
	init_texture(game, &textures->enemy[2][3],
		"./assets/textures/rat/rat4.xpm");
	init_texture(game, &textures->enemy[2][4],
		"./assets/textures/rat/rat5.xpm");
	init_texture(game, &textures->enemy[2][5],
		"./assets/textures/rat/rat6.xpm");
	init_texture(game, &textures->enemy[2][6],
		"./assets/textures/rat/rat7.xpm");
	init_texture(game, &textures->enemy[2][7],
		"./assets/textures/rat/rat8.xpm");
}

void	init_textures_officer(t_game *game, t_textures *textures)
{
	init_texture(game, &textures->enemy[0][0],
		"./assets/textures/officer/officer1.xpm");
	init_texture(game, &textures->enemy[0][1],
		"./assets/textures/officer/officer2.xpm");
	init_texture(game, &textures->enemy[0][2],
		"./assets/textures/officer/officer3.xpm");
	init_texture(game, &textures->enemy[0][3],
		"./assets/textures/officer/officer4.xpm");
	init_texture(game, &textures->enemy[0][4],
		"./assets/textures/officer/officer5.xpm");
	init_texture(game, &textures->enemy[0][5],
		"./assets/textures/officer/officer6.xpm");
	init_texture(game, &textures->enemy[0][6],
		"./assets/textures/officer/officer7.xpm");
	init_texture(game, &textures->enemy[0][7],
		"./assets/textures/officer/officer8.xpm");
}

void	init_textures_boss(t_game *game, t_textures *textures)
{
	init_texture(game, &textures->enemy[1][0],
		"./assets/textures/boss/boss1.xpm");
	init_texture(game, &textures->enemy[1][1],
		"./assets/textures/boss/boss2.xpm");
	init_texture(game, &textures->enemy[1][2],
		"./assets/textures/boss/boss3.xpm");
	init_texture(game, &textures->enemy[1][3],
		"./assets/textures/boss/boss4.xpm");
	init_texture(game, &textures->enemy[1][4],
		"./assets/textures/boss/boss5.xpm");
	init_texture(game, &textures->enemy[1][5],
		"./assets/textures/boss/boss6.xpm");
	init_texture(game, &textures->enemy[1][6],
		"./assets/textures/boss/boss7.xpm");
	init_texture(game, &textures->enemy[1][7],
		"./assets/textures/boss/boss8.xpm");
}

void	init_textures_weapons(t_game *game, t_textures *textures)
{
	init_texture(game, &textures->weapon[0][0],
		"./assets/textures/gun/gun1.xpm");
	init_texture(game, &textures->weapon[0][1],
		"./assets/textures/gun/gun2.xpm");
	init_texture(game, &textures->weapon[0][2],
		"./assets/textures/gun/gun3.xpm");
	init_texture(game, &textures->weapon[0][3],
		"./assets/textures/gun/gun4.xpm");
	init_texture(game, &textures->weapon[0][4],
		"./assets/textures/gun/gun5.xpm");
	init_texture(game, &textures->weapon[1][0],
		"./assets/textures/knife/knife1.xpm");
	init_texture(game, &textures->weapon[1][1],
		"./assets/textures/knife/knife2.xpm");
	init_texture(game, &textures->weapon[1][2],
		"./assets/textures/knife/knife3.xpm");
	init_texture(game, &textures->weapon[1][3],
		"./assets/textures/knife/knife4.xpm");
	init_texture(game, &textures->weapon[1][4],
		"./assets/textures/knife/knife5.xpm");
	init_texture(game, &textures->weapon[2][0], "./assets/textures/mg/mg1.xpm");
	init_texture(game, &textures->weapon[2][1], "./assets/textures/mg/mg2.xpm");
	init_texture(game, &textures->weapon[2][2], "./assets/textures/mg/mg3.xpm");
	init_texture(game, &textures->weapon[2][3], "./assets/textures/mg/mg4.xpm");
	init_texture(game, &textures->weapon[2][4], "./assets/textures/mg/mg5.xpm");
}
