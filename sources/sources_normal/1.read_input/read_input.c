/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:44:40 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/17 09:59:57 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_normal/cub3d.h"

void	read_input(int argc, char *argv[], t_map *map)
{
	int	fd;

	check_arguments(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_message("Failed to open file");
	read_textures(map, fd);
	read_map(map, fd);
	close(fd);
	validate_map(map);
}

void	read_textures(t_map *map, int fd)
{
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	while (line && *line)
	{
		tmp = line;
		ft_skip_whitespace(&tmp);
		if (!get_texture_or_color(tmp, map))
		{
			free(line);
			free_map(map, "texture file or color not readable", 1);
		}
		if (line)
			free(line);
		if (assigned_all(map))
			return ;
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (!assigned_all(map))
		free_map(map, "Missing textures or colors in .cub file", 1);
}

void	fill_with_space(t_map *map)
{
	int		row;
	int		coll;
	char	*temp;

	row = 0;
	while (map->map[row])
	{
		coll = 0;
		while (map->map[row][coll])
			coll++;
		if (coll < map->cols)
		{
			temp = ft_realloc(map->map[row], sizeof(char) * (coll + 1),
					sizeof(char) * (map->cols + 1));
			if (!temp)
				free_map(map, "Failed to allocate memory for row", 1);
			map->map[row] = temp;
			while (coll < map->cols)
				map->map[row][coll++] = ' ';
			map->map[row][coll] = '\0';
		}
		row++;
	}
}

void	read_map_aux(t_map *map, int row, char **temp, char *line)
{
	temp = ft_realloc(map->map, sizeof(char *) * (row + 1), sizeof(char *)
			* (row + 2));
	if (!temp)
	{
		free(line);
		if (map->map)
			free_map(map, "Memory allocation failed", 1);
		error_message("Memory allocation failed");
	}
	map->map = temp;
	map->map[row] = ft_strtrim(line, "\n");
	if (!map->map[row])
	{
		free(line);
		free_map(map, "Memory allocation failed", 1);
	}
}

void	read_map(t_map *map, int fd)
{
	char	*line;
	int		row;
	char	**temp;

	row = 0;
	temp = NULL;
	line = get_next_line(fd);
	while (line && *line == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		read_map_aux(map, row, temp, line);
		free(line);
		line = get_next_line(fd);
		row++;
	}
	remove_extra_rows(map, row, temp);
}
