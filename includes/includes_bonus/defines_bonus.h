/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:37:18 by andre-da          #+#    #+#             */
/*   Updated: 2024/06/19 13:12:29 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_BONUS_H
# define DEFINES_BONUS_H

# ifdef LINUX
/* ----------------- Linux---------------- */
#  include "../../libraries/minilibx-linux/mlx.h"
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define LEFT_KEY 65361
#  define RIGHT_KEY 65363
#  define SHIFT 0xFFE1
#  define SPACEBAR 32
#  define LEFT_BTN 65361  // Left arrow key
#  define RIGHT_BTN 65363 // Right arrow key
#  define SHOOT 102       // 's' key
#  define SWITCH 114      // 'd' key
# else
/* ------------------ Mac ----------------- */
#  include "../../libraries/minilibx-mac/mlx.h"
#  define ESC 0x35
#  define W 0x0D
#  define A 0x00
#  define S 0x01
#  define D 0x02
#  define LEFT_KEY 0x7B
#  define RIGHT_KEY 0x7C
#  define SHIFT 0x101
#  define SPACEBAR 0x31
#  define LEFT_BTN 0xF0
#  define RIGHT_BTN 0xF1
#  define SHOOT 0x03
#  define SWITCH 0x0F
# endif
/* --------------- General --------------- */
# define WHITESPACE " \t\n\r\f\v"
# define VALID_CHARS "NSEW01BOR \t\n\r\f\v\0"
# define WS_COMMA " \t\n\r\f\v,"
# define QUIT 1
# define EPSILON 0.0001
/* -------------- PI Values -------------- */
# define PI 3.141592653f
# define _05PI 1.5707963265f
# define _15PI 4.71238898f
# define _2PI 6.283185306f
/* -------------- Directions ------------- */
# define NORTH _15PI
# define SOUTH _05PI
# define EAST 0
# define WEST PI
# define NORTH_ 0
# define SOUTH_ 1
# define EAST_ 1
# define WEST_ 0
# define NW 1
# define NE 2
# define SW 3
# define SE 4
/* -------------- Movements ------------- */
# define UP 1
# define RIGHT 1
# define LEFT -1
# define DOWN -1
# define RESET 0
# define MOUSE_SENSITIVITY 0.003
/* ----------------- Game ---------------- */
# define PLAYER "NSEW"
# define ENEMY "BOR"
# define SCALE 50
# define PSIZE 12
# define PCENTER 6
# define JUMP_SPEED 10
# define MAX_JUMP_HEIGHT 140
# define MAX_JUMP_SPEED 30
# define ROT_SPEED 0.02
# define BUFFER 10
# define WALL 49
# define VISITED 85
# define EMPTY 48
# define WON 89
# define WIDTH 1080
# define HEIGHT 720
# define PLAYER_VISION 1.0471975511965976f
# define WALL_SCALE 8000
# define N_ 0x000000
# define S_ 0xFF4500
# define W_ 0xFFFFFF
# define E_ 0xD63A00
# define GUN 0
# define KNIFE 1
# define SHOOT_SPEED 5
# define OFFICER 0
# define BOSS 1
# define RAT 2
# define ENEMY_SCALE 8000
# define ESIZE 20
# define ANIMATION_SPEED 15
# define MIN_DISTANCE 15
/* --------------- Minimap -------------- */
# define MINI_ROWS 5
# define MINI_COLS 7
# define MINI_SCALE 25
# define SCALE_FACTOR 2
# define MINI_PCENTER 3
# define MINI_PSIZE 6
# define ADJUST 10
/* ---------------- Colors --------------- */
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define ORANGE 0xFF4500
# define GREY 0xFF8080
# define PURPLE 0x800080
# define BROWN 0xA52A2A
# define PINK 0xFFC0CB
# define LIME 0x00FF00
# define GOLD 0xFFD700
# define SILVER 0xC0C0C0
# define INDIGO 0x4B0082
# define TEAL 0x008080
# define MAROON 0x800000
/* ---------------- Images --------------- */
# define SCREEN BLACK
# define SPACE WHITE
# define WALLS BROWN
# define PLAYER_ BLUE

#endif
