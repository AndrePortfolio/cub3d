/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:37:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/20 10:42:59 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

# include "cub3d_bonus.h"

typedef struct s_rgb
{
	int					red;
	int					green;
	int					blue;
}						t_rgb;

typedef struct s_point
{
	float				x;
	float				y;
}						t_point;

typedef struct s_point_i
{
	int					x;
	int					y;
}						t_point_i;

typedef struct s_enemy
{
	int					type;
	t_point				pos;
	t_point				left;
	t_point				right;
	t_point				dir_vec;
	int					speed;
	int					size;
	int					frame;
	bool				shot;
	bool				dead;
}						t_enemy;

typedef struct s_map
{
	char				**map;
	int					rows;
	int					cols;
	int					fd;
	t_point_i			player;
	struct s_enemy		**enemies;
	int					enemy_count;
	float				player_dir;
	char				*no_texture;
	char				*so_texture;
	char				*we_texture;
	char				*ea_texture;
	struct s_rgb		f_color;
	struct s_rgb		c_color;
}						t_map;

typedef struct s_img
{
	void				*img_ptr;
	char				*pixels_ptr;
	int					bits_per_pixel;
	int					endian;
	int					line_len;
	int					width;
	int					height;
}						t_img;

typedef struct s_textures
{
	struct s_img		north;
	struct s_img		south;
	struct s_img		east;
	struct s_img		west;
	struct s_img		aim;
	struct s_img		map;
	struct s_img		sky;
	struct s_img		ground;
	struct s_img		weapon[3][5];
	struct s_img		enemy[3][8];
}						t_textures;

typedef struct s_game
{
	void				*mlx;
	void				*win;
	char				**pixel_map;
	bool				is_player_dead;
	struct s_map		*map;
	struct s_img		img;
	int					width;
	int					height;
	struct s_player		*player;
	int					dir;
	struct s_textures	*textures;
	int					f_color;
	int					c_color;
	int					color;
	float				fraction_x;
	float				fraction_y;
	struct s_enemy		**enemies;
	int					enemy_count;
}						t_game;

typedef struct s_player
{
	int					up_down;
	int					left_right;
	int					rot;
	t_point				pos;
	float				p_angle;
	int					look_dir;
	int					speed;
	float				jump_height;
	bool				jumping;
	bool				jump_peak;
	int					shooting;
	int					weapon;
	int					prev_mouse_x;
	int					prev_mouse_y;
}						t_player;

typedef struct s_raycaster
{
	t_point				dir;
	t_point				scalingf;
	t_point				ray_len;
	t_point_i			map_loc;
	t_point_i			map_step;
	float				len;
	t_point				intersection;
	t_point				start;
	bool				wall;
	bool				enemy;
	int					enemy_type;
	float				distance_enemy;
	float				tex_x;
	int					enemy_id;
}						t_raycaster;

typedef struct s_minimap
{
	int					start_x;
	int					start_y;
	int					end_x;
	int					end_y;
	int					hori_vision;
	int					vert_vision;
	int					initial_x;
	int					initial_y;
	t_point				player;
}						t_minimap;

typedef struct s_positions
{
	int					pos_x;
	int					pos_y;
	int					img_x;
	int					img_y;
	int					y;
	int					x;
}						t_positions;

typedef struct s_ray_tools
{
	t_player			*player;
	float				distance;
	float				adjusted;
	t_point				top;
	t_point				bottom;
	float				angle;
	int					wall_height;
}						t_ray_tools;

typedef struct s_line_tools
{
	t_point				q1;
	t_point				q2;
	t_point				r;
	t_point				s;
	t_point				qp;
	float				cross;
	float				t;
	float				u;
}						t_line_tools;

typedef struct s_drawline_tools
{
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					err;
	int					e2;
}						t_drawline_tools;

typedef struct s_enemy_tools
{
	t_point				ray_end;
	t_enemy				**enemy;
	t_point				intersection;
	int					i;
	float				distance;
	float				enemy_line_length;
	float				intersection_pos;
}						t_enemy_tools;

typedef struct s_drawenemy_tools
{
	int					color;
	float				tex_y;
	float				step;
	t_point				top;
	t_point				bottom;
	int					enemy_height;
	float				distance_factor;
	int					enemy_scale;
}						t_drawenemy_tools;

typedef struct s_sprite_tools
{
	t_enemy				**enemy;
	t_point				new_pos;
	t_point				wall_in;
	int					close_to_others;
	char				**map;
}						t_sprite_tools;

typedef struct s_map_tools
{
	t_textures			*texture;
	int					color;
	t_point				pixel;
	t_point				scale;
	t_point				tex;
	int					mini_width;
	int					mini_height;
}						t_map_tools;

typedef struct s_weapon_tools
{
	t_point_i			pixel;
	t_point				tex;
	int					color;
	int					scale;
	int					type;
}						t_weapon_tools;

#endif
