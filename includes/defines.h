/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/04/07 21:48:26 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define MINIMAP_SCALE 10

# define WIN_TITLE "cub3D"

# define NB_CEIL_TEX 5

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define MOVE_SPEED 0.07
# define ROT_SPEED 0.04
# define COLLISION_MARGIN 0.4

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_SPACE 32
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_DESTROY 17

# define VALID_MAP_CHARS "01NSEWD "
# define SPAWN_CHARS "NSEW"

# define NB_ELEMENTS 6
# define SUCCESS 0
# define FAILURE 1

# define ERR_ARGS "Usage: ./cub3D <map.cub>"
# define ERR_EXT "Invalid file extension (expected .cub)"
# define ERR_OPEN "Cannot open file"
# define ERR_MLX_INIT "Failed to initialize miniLibX"
# define ERR_MLX_WIN "Failed to create window"
# define ERR_MLX_IMG "Failed to create image"
# define ERR_TEX_LOAD "Failed to load texture"
# define ERR_DUP_ELEM "Duplicate element in .cub file"
# define ERR_MISS_ELEM "Missing element in .cub file"
# define ERR_INV_ELEM "Invalid element identifier"
# define ERR_COLOR_FMT "Invalid color format (expected R,G,B)"
# define ERR_COLOR_RANGE "Color value out of range [0-255]"
# define ERR_MAP_CHAR "Invalid character in map"
# define ERR_MAP_CLOSED "Map is not closed by walls"
# define ERR_MAP_PLAYER "Map must have exactly one player spawn (N/S/E/W)"
# define ERR_MAP_EMPTY "Map is empty"
# define ERR_MALLOC "Memory allocation failed"
# define ERR_ALLOC "Memory allocation failed"

#endif