/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:48:30 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/13 17:34:25 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

void	init_texture(t_game *game, t_img *texture_img, char *texture)
{
	texture_img->img_ptr = mlx_xpm_file_to_image(game->mlx, texture,
			&texture_img->width, &texture_img->height);
	if (!texture_img->img_ptr)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_map(game->map, "Failed to initialize texture", 1);
	}
	texture_img->pixels_ptr = mlx_get_data_addr(texture_img->img_ptr,
			&texture_img->bits_per_pixel, &texture_img->line_len,
			&texture_img->endian);
}

void	init_textures_aux(t_game *game, t_textures *textures)
{
	init_texture(game, &textures->enemy[0][0],
		"./assets/textures/officer/officer1.xpm");
	init_texture(game, &textures->enemy[0][1],
		"./assets/textures/officer/officer2.xpm");
	init_texture(game, &textures->enemy[0][2],
		"./assets/textures/officer/officer3.xpm");
	init_texture(game, &textures->enemy[0][3],
		"./assets/textures/officer/officer4.xpm");
	init_texture(game, &textures->enemy[1][0],
		"./assets/textures/boss/boss1.xpm");
	init_texture(game, &textures->enemy[1][1],
		"./assets/textures/boss/boss2.xpm");
	init_texture(game, &textures->enemy[1][2],
		"./assets/textures/boss/boss3.xpm");
	init_texture(game, &textures->enemy[1][3],
		"./assets/textures/boss/boss4.xpm");
	init_texture(game, &textures->enemy[2][0],
		"./assets/textures/rat/rat1.xpm");
	init_texture(game, &textures->enemy[2][1],
		"./assets/textures/rat/rat2.xpm");
	init_texture(game, &textures->enemy[2][2],
		"./assets/textures/rat/rat3.xpm");
	init_texture(game, &textures->enemy[2][3],
		"./assets/textures/rat/rat4.xpm");
}

void	init_textures_aux2(t_game *game, t_textures *textures)
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

void	init_textures(t_game *game, t_textures *textures)
{
	init_texture(game, &textures->north, game->map->no_texture);
	init_texture(game, &textures->south, game->map->so_texture);
	init_texture(game, &textures->east, game->map->ea_texture);
	init_texture(game, &textures->west, game->map->we_texture);
	init_texture(game, &textures->aim, "./assets/textures/aim.xpm");
	init_texture(game, &textures->map, "./assets/textures/map.xpm");
	init_texture(game, &textures->ground, "./assets/textures/floor.xpm");
	init_texture(game, &textures->sky, "./assets/textures/sky.xpm");
	init_textures_aux(game, textures);
	init_textures_aux2(game, textures);
	game->textures = textures;
}
