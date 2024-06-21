/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:37:01 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/20 10:40:38 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structs.h"

/* ------------------------------- Read Input ------------------------------ */
/* ------------------------------------------------------------------------- */
void	read_input(int argc, char *argv[], t_map *map);
void	check_arguments(int argc, char *argv[]);
bool	is_cub(char *file);
void	read_textures(t_map *map);
void	read_map(t_map *map);
void	remove_extra_rows(t_map *map, int rows, char **temp);
int		get_texture(char *line, char type, t_map *map);
void	assign_color(int i, char *num, char type, t_map *map);
int		get_color(char *line, char type, t_map *map);
bool	assigned_all(t_map *map);
void	init_map(t_map *map);
int		get_texture_or_color(char *tmp, t_map *map);
void	copy_color(char **trimmed_num, char *line, int i);
int		num_length(char *line, int num_start);
int		num_start(char *line);

/* ----------------------------- Validate map ------------------------------ */
/* ------------------------------------------------------------------------- */
void	validate_map(t_map *map);
bool	valid_color(int color);
bool	invalid_color(t_map *map);
bool	map_split(t_map *map);
void	get_player_coordinates(t_map *map, int rows, int coll);
bool	invalid_characters(t_map *map);
bool	surrounded_by_walls(t_map *map);
void	fill_with_space(t_map *map);

/* ------------------------------- Mlx Init -------------------------------- */
/* ------------------------------------------------------------------------- */
void	start_game(t_map *map);
void	init_mlx(t_game *game, t_textures *textures, t_player *player,
			t_map *map);
void	init_game_struct(t_game *game, t_player *player, t_map *map);
void	init_window(t_game *game, t_map *map);
void	init_image(t_game *game);
void	init_events(t_game *game);
int		key_press(int keysym, t_game *game);
int		key_release(int keysym, t_game *game);
int		convert(t_rgb color);
void	init_textures(t_game *game, t_textures *textures);

/* ------------------------------- Rendering ------------------------------- */
/* ------------------------------------------------------------------------- */
int		render(t_game *game);
void	put_pixel_to_img(t_game *game, int x, int y, int color);
void	move_player(t_game *game, float move_x, float move_y);
void	check_movements(t_game *game);
void	draw_vline(t_game *game, int x, int start_y, int end_y);
int		get_texture_color(t_game *game, int tex_x, int tex_y);
void	draw_textures(t_game *game, int x, int start_y, int end_y);
void	jumping(t_player *player);

/* ------------------------------ Ray Caster ------------------------------- */
/* ------------------------------------------------------------------------- */
void	init_ray(t_raycaster *ray, t_player *player, float angle);
float	cast_ray(t_game *game, float angle, t_raycaster *ray);
void	raycast(t_game *game, t_raycaster *ray);
void	check_direction(t_game *game, t_raycaster *ray, int visited);
void	closer_distance(t_raycaster *ray, int *visited);
void	check_dir(t_raycaster *ray);

/* ------------------------------- Movements ------------------------------- */
/* ------------------------------------------------------------------------- */
void	rotate_player(t_player *player);
void	jumping(t_player *player);
void	move_player(t_game *game, float new_x, float new_y);
void	check_movements(t_game *game);
int		mouse_hook(int x, t_player *player);

/* -------------------------------- Utils ---------------------------------- */
/* ------------------------------------------------------------------------- */
void	print_textures(t_map *map_info);
void	print_map(char **map);
void	print_pixel_map(t_game *game);

/* ----------------------------- Close Program ----------------------------- */
/* ------------------------------------------------------------------------- */
void	error_message(char *str);
void	free_map(t_map *map, char *str, int status);
int		close_window(t_game *game, int status, int exit);
void	free_map_copy(char **map);
void	free_textures(t_game *game, t_textures *textures);
void	clean_up(t_game *game, char *str, int status);

#endif
