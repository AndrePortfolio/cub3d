/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:49:45 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/13 15:44:05 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes_bonus/cub3d_bonus.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	init_map(&map);
	read_input(argc, argv, &map);
	start_game(&map);
	return (0);
}
