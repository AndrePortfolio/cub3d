/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:48:34 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/13 16:33:57 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes_bonus/cub3d_bonus.h"

int	get_img_color(int tex_x, int tex_y, t_img texture)
{
	int	color;
	int	bpp;
	int	len;

	bpp = texture.bits_per_pixel;
	len = texture.line_len;
	if (tex_x < 0 || tex_x >= texture.width || tex_y < 0
		|| tex_y >= texture.height)
		return (0);
	color = *(int *)&texture.pixels_ptr[tex_x * (bpp / 8) + (tex_y * len)];
	return (color);
}

void	draw_texture(t_game *game, t_img texture, t_positions p)
{
	int		color;
	float	scale_x;
	float	scale_y;
	float	tex_x;
	float	tex_y;

	scale_x = (float)texture.width / MINI_SCALE;
	scale_y = (float)texture.height / MINI_SCALE;
	tex_x = (int)(p.img_x * scale_x) % MINI_SCALE;
	tex_y = (int)(p.img_y * scale_y) % MINI_SCALE;
	color = get_img_color((int)tex_x, (int)tex_y, texture);
	if (!((color >> 24) & 0xFF))
		put_pixel_to_img(game, p.pos_x, p.pos_y - ADJUST, color);
}

void	minimap_aux(t_game *game, t_minimap mini, t_textures *texture,
		t_positions p)
{
	p.x = mini.start_x;
	p.img_x = 0;
	while (p.x < mini.end_x)
	{
		p.pos_x = (mini.start_x - mini.initial_x + (WIDTH - (WIDTH / 5) + (WIDTH
						/ SCALE)));
		p.pos_y = (mini.start_y - mini.initial_y + (HEIGHT - (HEIGHT / 5)
					+ (HEIGHT / SCALE)));
		if (p.y < (game->map->rows * SCALE))
			if (game->map->map[(int)(p.y / SCALE)][(int)(p.x / SCALE)] == WALL)
				draw_texture(game, texture->north, p);
		mini.start_x++;
		p.x += SCALE_FACTOR;
		p.img_x++;
	}
}

void	minimap(t_game *game, t_raycaster *ray)
{
	t_player	*player;
	t_minimap	mini;
	t_textures	*texture;
	t_positions	p;

	texture = game->textures;
	player = game->player;
	init_minimap(player, &mini);
	p.img_y = 0;
	p.y = mini.start_y;
	while (p.y < mini.end_y)
	{
		get_start_x(player, &mini);
		minimap_aux(game, mini, texture, p);
		mini.start_y++;
		p.y += SCALE_FACTOR;
		p.img_y++;
	}
	render_player_and_rays(game, ray, mini);
}

void	init_minimap(t_player *player, t_minimap *mini)
{
	mini->hori_vision = (SCALE * MINI_COLS / 2) - MINI_PSIZE;
	mini->vert_vision = (SCALE * MINI_ROWS / 2) - MINI_PSIZE;
	mini->start_y = player->pos.y;
	get_start_x(player, mini);
	if (mini->start_y - mini->vert_vision >= 0)
		mini->start_y -= mini->vert_vision;
	else
		mini->start_y = 0;
	mini->end_x = mini->start_x + (SCALE * MINI_COLS);
	mini->end_y = mini->start_y + (SCALE * MINI_ROWS);
	mini->initial_x = mini->start_x;
	mini->initial_y = mini->start_y;
}
