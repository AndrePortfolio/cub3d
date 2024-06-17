/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:37:21 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/17 11:33:37 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_BONUS_H
# define FUNCTIONS_BONUS_H

# include "structs_bonus.h"

/* ------------------------------- Read Input ------------------------------ */
/* ------------------------------------------------------------------------- */
void	read_input(int argc, char *argv[], t_map *map);
void	check_arguments(t_map *map, int argc, char *argv[]);
bool	is_cub(char *file);
void	read_textures(t_map *map, int fd);
void	read_map(t_map *map, int fd);
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
int		mouse_hook(int x, t_player *player);
int		convert(t_rgb color);
void	init_textures(t_game *game, t_textures *textures);

/* ------------------------------- Rendering ------------------------------- */
/* ------------------------------------------------------------------------- */
int		render(t_game *game);
void	put_pixel_to_img(t_game *game, int x, int y, int color);
void	draw_line(t_game *game, t_point_i start, t_point_i end);
void	move_player(t_game *game, float move_x, float move_y);
void	check_movements(t_game *game);
void	draw_vline(t_game *game, int x, int start_y, int end_y);
int		get_texture_color(t_game *game, int tex_x, int tex_y);
void	draw_textures(t_game *game, int x, int start_y, int end_y);
void	jumping(t_player *player);
void	prepate_to_move_player(t_player *p, float *new_x, float *new_y);
int		get_map_color(int tex_x, int tex_y, t_textures *texture);
void	init_map_tools(t_game *game, t_map_tools *m);
void	aim(t_game *game);

/* --------------------------- Weapon Rendering ---------------------------- */
/* ------------------------------------------------------------------------- */
void	draw_weapon(t_game *game, int frame);
int		get_weapon_color(t_game *game, int tex_x, int tex_y, int frame);
void	render_weapon(t_game *game);

/* --------------------------- Sprite Rendering ---------------------------- */
/* ------------------------------------------------------------------------- */
// void	render_sprites(t_game *game);
void	get_enemy_distance(t_raycaster *ray, t_game *game);
t_point	get_normalized_vector(t_point p1, t_point p2);
void	get_enemy_positions(t_game *game);
void	draw_enemy(t_game *game, int x, t_raycaster *ray);
void	animate_sprites(t_game *game);
void	move_sprites(t_game *game);

/* ------------------------------ Ray Caster ------------------------------- */
/* ------------------------------------------------------------------------- */
void	init_ray(t_raycaster *ray, t_player *player, float angle);
float	cast_ray(t_raycaster *ray, t_game *game, float angle);
void	raycast(t_game *game, t_raycaster *ray);
void	check_direction(t_game *game, t_raycaster *ray, int visited);

/* ------------------------------- Movements ------------------------------- */
/* ------------------------------------------------------------------------- */
void	rotate_player(t_player *player);
void	jumping(t_player *player);
void	move_player(t_game *game, float new_x, float new_y);
void	check_movements(t_game *game);
void	init_enemy_tools(t_enemy_tools *e, t_game *game, t_raycaster *ray);
bool	lines_intersect(t_point p1, t_point p2, t_enemy *enemy,
			t_point *intersection);

/* ------------------------------- Mini Map -------------------------------- */
/* ------------------------------------------------------------------------- */
void	minimap(t_game *game, t_raycaster *ray);
void	init_minimap(t_player *player, t_minimap *mini);
void	render_player_and_rays(t_game *game, t_raycaster *ray, t_minimap mini);
void	render_player(t_game *game, int start_x, int start_y);
void	raycast_2d(t_game *game, t_raycaster *ray, t_minimap mini);
void	cast_2d_ray(t_game *game, float angle, t_raycaster *ray,
			t_minimap mini);
void	init_2d_ray(t_raycaster *ray, t_player *player, float angle);
void	adjust_raylen(t_raycaster *ray, float angle, t_minimap mini,
			t_player *player);
void	draw_ray(t_game *game, t_player *player, t_raycaster *ray,
			t_minimap mini);
void	get_start_x(t_player *player, t_minimap *mini);
void	draw_ray_aux1(t_point_i *start, t_point_i *end, t_point close_to_b);
void	draw_ray_aux2(t_point_i *start, t_point_i *end, t_point close_to_b,
			t_point centered);
void	draw_ray_aux3(t_point_i *start, t_point_i *end, t_point close_to_b,
			t_point centered);
void	draw_ray_aux4(t_point_i *start, t_point_i *end, t_point centered);

/* -------------------------------- Utils ---------------------------------- */
/* ------------------------------------------------------------------------- */
void	print_textures(t_map *map_info);
void	print_map(char **map);
void	print_pixel_map(t_game *game);

/* ----------------------------- Close Program ----------------------------- */
/* ------------------------------------------------------------------------- */
void	error_message(t_map *map, char *str);
void	free_map(t_map *map, char *str, int status);
int		close_window(t_game *game, int status, int exit);
void	player_dead(t_game *game);
void	free_map_copy(char **map);
void	clean_up(t_game *game, char *str, int status);
void	free_enemies(t_map *map);
void	free_textures(t_game *game, t_textures *textures);

#endif
