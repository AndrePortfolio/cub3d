/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:29:22 by btoksoez          #+#    #+#             */
/*   Updated: 2024/06/17 11:32:34 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_normal/cub3d.h"

int	num_start(char *line)
{
	int	num_start;

	num_start = 0;
	while (line[num_start] && (line[num_start] == ' '
			|| line[num_start] == '\t'))
		num_start++;
	return (num_start);
}

int	num_length(char *line, int num_start)
{
	int	num_length;

	num_length = 0;
	while (line[num_start + num_length] && line[num_start + num_length] != ','
		&& line[num_start + num_length] != '\n')
		num_length++;
	return (num_length);
}

void	copy_color(char **trimmed_num, char *line, int i)
{
	int	j;

	j = 0;
	while (j < num_length(line, num_start(line)))
	{
		trimmed_num[i][j] = line[num_start(line) + j];
		j++;
	}
	trimmed_num[i][num_length(line, num_start(line))] = '\0';
}
