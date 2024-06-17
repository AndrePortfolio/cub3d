/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:46:11 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/13 15:42:17 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes_normal/cub3d.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	init_map(&map);
	read_input(argc, argv, &map);
	start_game(&map);
	return (0);
}
