/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:48:30 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/21 09:04:59 by btoksoez         ###   ########.fr       */
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
		printf("%s\n", texture);
		free_map(game->map, "Failed to initialize texture", 1);
	}
	texture_img->pixels_ptr = mlx_get_data_addr(texture_img->img_ptr,
			&texture_img->bits_per_pixel, &texture_img->line_len,
			&texture_img->endian);
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
	init_textures_officer(game, textures);
	init_textures_boss(game, textures);
	init_textures_rat(game, textures);
	init_textures_weapons(game, textures);
	game->textures = textures;
}
