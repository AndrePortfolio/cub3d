/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:35:05 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/17 10:07:16 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

int	get_texture_or_color(char *tmp, t_map *map)
{
	if (ft_strlen(tmp) >= 3 && *tmp == 'N' && *(tmp + 1) == 'O')
		return (get_texture(tmp, 'N', map));
	else if (ft_strlen(tmp) >= 3 && *tmp == 'S' && *(tmp + 1) == 'O')
		return (get_texture(tmp, 'S', map));
	else if (ft_strlen(tmp) >= 3 && *tmp == 'W' && *(tmp + 1) == 'E')
		return (get_texture(tmp, 'W', map));
	else if (ft_strlen(tmp) >= 3 && *tmp == 'E' && *(tmp + 1) == 'A')
		return (get_texture(tmp, 'E', map));
	else if (*tmp == 'F' && ft_strchr(WHITESPACE, *(tmp + 1)))
		return (get_color(tmp, 'F', map));
	else if (*tmp == 'C' && ft_strchr(WHITESPACE, *(tmp + 1)))
		return (get_color(tmp, 'C', map));
	return (true);
}

void	check_arguments(t_map *map, int argc, char *argv[])
{
	if (argc != 2)
		error_message(map, "Invalid number of arguments");
	if (!is_cub(argv[1]))
		error_message(map, "File must be of type .cub");
}

bool	is_cub(char *file)
{
	int	i;

	i = 0;
	while (file[i] && file[i] != '.')
		i++;
	if (ft_strcmp(file + i, ".cub") == 0)
		return (true);
	return (false);
}
