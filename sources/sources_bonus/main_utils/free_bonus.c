/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:17:54 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/06/13 15:44:46 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

void	free_map(t_map *map, char *str, int status)
{
	int	rows;

	rows = 0;
	if (map->map)
	{
		while (map->map[rows])
		{
			free(map->map[rows]);
			rows++;
		}
		free(map->map);
	}
	free(map->ea_texture);
	free(map->no_texture);
	free(map->we_texture);
	free(map->so_texture);
	if (status == 1)
		error_message(map, str);
}

void	destroy_images(t_game *game, t_textures *textures)
{
	if (textures->north.img_ptr)
		mlx_destroy_image(game->mlx, textures->north.img_ptr);
	if (textures->west.img_ptr)
		mlx_destroy_image(game->mlx, textures->west.img_ptr);
	if (textures->south.img_ptr)
		mlx_destroy_image(game->mlx, textures->south.img_ptr);
	if (textures->east.img_ptr)
		mlx_destroy_image(game->mlx, textures->east.img_ptr);
	if (textures->aim.img_ptr)
		mlx_destroy_image(game->mlx, textures->aim.img_ptr);
	if (textures->map.img_ptr)
		mlx_destroy_image(game->mlx, textures->map.img_ptr);
	if (textures->ground.img_ptr)
		mlx_destroy_image(game->mlx, textures->ground.img_ptr);
	if (textures->sky.img_ptr)
		mlx_destroy_image(game->mlx, textures->sky.img_ptr);
}

void	free_textures(t_game *game, t_textures *textures)
{
	int	i;
	int	j;

	destroy_images(game, textures);
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 5)
			if (textures->weapon[i][j].img_ptr)
				mlx_destroy_image(game->mlx, textures->weapon[i][j].img_ptr);
	}
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 4)
			if (textures->enemy[i][j].img_ptr)
				mlx_destroy_image(game->mlx, textures->enemy[i][j].img_ptr);
	}
}
