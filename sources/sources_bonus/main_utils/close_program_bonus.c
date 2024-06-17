/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:49:26 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/13 17:34:25 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

void	error_message(t_map *map, char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	free_enemies(map);
	exit(1);
}

int	close_window(t_game *game, int status, int exit)
{
	if (exit == WON)
		clean_up(game, "You Won!", status);
	else
		clean_up(game, "Game Over!", status);
	return (0);
}

void	free_map_copy(char **map)
{
	int	rows;

	rows = 0;
	if (map)
	{
		while (map[rows])
		{
			free(map[rows]);
			rows++;
		}
		free(map);
	}
}

void	free_enemies(t_map *map)
{
	int	i;

	i = 0;
	if (!map->enemies)
		return ;
	while (i < map->enemy_count)
	{
		free(map->enemies[i++]);
	}
	free(map->enemies);
}

void	clean_up(t_game *game, char *str, int status)
{
	free_textures(game, game->textures);
	free_map(game->map, NULL, 0);
	mlx_destroy_image(game->mlx, game->img.img_ptr);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	if (status)
		error_message(game->map, str);
	else
	{
		free_enemies(game->map);
		ft_printf("%s\n", str);
		exit(0);
	}
}
