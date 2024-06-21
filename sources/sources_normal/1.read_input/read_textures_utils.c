/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:44:47 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/18 12:25:50 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_normal/cub3d.h"

int	get_texture(char *line, char type, t_map *map)
{
	char	*file;

	line += 2;
	ft_skip_whitespace(&line);
	file = ft_strdup_delimiter(line, WHITESPACE);
	if (access(file, F_OK) != 0 || access(file, R_OK) != 0)
	{
		free(file);
		return (false);
	}
	if (type == 'N')
		map->no_texture = file;
	else if (type == 'S')
		map->so_texture = file;
	else if (type == 'W')
		map->we_texture = file;
	else if (type == 'E')
		map->ea_texture = file;
	line += ft_strlen(file);
	return (true);
}

void	assign_color(int i, char *num, char type, t_map *map)
{
	if (i == 0 && type == 'F')
		map->f_color.red = ft_atoi(num);
	else if (i == 1 && type == 'F')
		map->f_color.green = ft_atoi(num);
	else if (i == 2 && type == 'F')
		map->f_color.blue = ft_atoi(num);
	else if (i == 0 && type == 'C')
		map->c_color.red = ft_atoi(num);
	else if (i == 1 && type == 'C')
		map->c_color.green = ft_atoi(num);
	else if (i == 2 && type == 'C')
		map->c_color.blue = ft_atoi(num);
}

int	get_color(char *line, char type, t_map *map)
{
	char	*trimmed_num[3];
	int		i;

	line++;
	ft_skip_whitespace(&line);
	i = 0;
	while (i < 3)
	{
		if (num_length(line, num_start(line)) == 0
			|| num_length(line, num_start(line)) > 3)
			return (false);
		trimmed_num[i] = malloc(num_length(line, num_start(line)) + 1);
		if (!trimmed_num[i])
			return (false);
		copy_color(trimmed_num, line, i);
		if (ft_atoi(trimmed_num[i]) < 0 || !ft_isdigit_str(trimmed_num[i]))
			return (false);
		assign_color(i, trimmed_num[i], type, map);
		line += num_start(line) + num_length(line, num_start(line)) + 1;
		free(trimmed_num[i]);
		i++;
	}
	if (*line != '\0')
		return (false);
	return (true);
}

bool	assigned_all(t_map *map)
{
	if (map->ea_texture && map->no_texture && map->so_texture && map->we_texture
		&& map->f_color.blue != -1 && map->f_color.green != -1
		&& map->f_color.red != -1 && map->c_color.green != -1
		&& map->c_color.blue != -1 && map->f_color.red != -1)
		return (true);
	return (false);
}
