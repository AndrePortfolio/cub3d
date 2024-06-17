/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:49:09 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/13 15:44:46 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

t_point	get_normalized_vector(t_point p1, t_point p2)
{
	t_point	dir;
	float	len;

	len = sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
	dir.x = (p2.x - p1.x) / len;
	dir.y = (p2.y - p1.y) / len;
	return (dir);
}

// Function to compute the cross product of two vectors
float	cross_product(t_point a, t_point b)
{
	return ((a.x * b.y) - (a.y * b.x));
}

void	init_line_tools(t_line_tools *line, t_enemy *enemy, t_point p1,
		t_point p2)
{
	line->q1 = enemy->left;
	line->q2 = enemy->right;
	line->r.x = p2.x - p1.x;
	line->r.y = p2.y - p1.y;
	line->s.x = line->q2.x - line->q1.x;
	line->s.y = line->q2.y - line->q1.y;
}

// Function to check if two line segments (p1, p2) and (q1, q2) intersect
bool	lines_intersect(t_point p1, t_point p2, t_enemy *enemy,
		t_point *intersection)
{
	t_line_tools	line;

	init_line_tools(&line, enemy, p1, p2);
	line.cross = cross_product(line.r, line.s);
	if (line.cross == 0)
		return (false);
	line.qp.x = line.q1.x - p1.x;
	line.qp.y = line.q1.y - p1.y;
	line.t = cross_product(line.qp, line.s) / line.cross;
	line.u = cross_product(line.qp, line.r) / line.cross;
	if (line.t >= 0 && line.t <= 1 && line.u >= 0 && line.u <= 1)
	{
		intersection->x = p1.x + line.t * line.r.x;
		intersection->y = p1.y + line.t * line.r.y;
		return (true);
	}
	return (false);
}

void	init_enemy_tools(t_enemy_tools *e, t_game *game, t_raycaster *ray)
{
	e->ray_end.x = ray->start.x + ray->dir.x * ray->len;
	e->ray_end.y = ray->start.y + ray->dir.y * ray->len;
	e->enemy = game->enemies;
	e->i = 0;
}
