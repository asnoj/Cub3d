/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/04/07 19:26:33 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "defines.h"
# include "get_next_line_bonus.h"
# include <X11/Xlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum e_direction
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
}				t_direction;

// Change l'enum dans cub3d.h
typedef enum e_tex_index
{
	TEX_NO = 0,
	TEX_SO = 1,
	TEX_WE = 2,
	TEX_EA = 3,
	TEX_FLOOR = 4,
	TEX_CEIL = 5,
	TEX_DOOR = 10
}				t_tex_index;

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
	int			hex;
	int			is_set;
}				t_color;

typedef struct s_config
{
	char		*tex_path[4];
	t_color		floor;
	t_color		ceiling;
}				t_config;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
}				t_map;

typedef struct s_player
{
	double		pos_x;
	int			spawn_count;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_ray
{
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		perp_wall_dist;
	double		wall_x;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			is_door;
}				t_ray;

typedef struct s_tex_info
{
	int			tex_index;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
}				t_tex_info;

typedef struct s_floor_ceiling
{
	int			y;
	int			x;
	int			cell_x;
	int			cell_y;
	int			ceil_idx;
	double		ray_dir_x0;
	double		ray_dir_y0;
	double		ray_dir_x1;
	double		ray_dir_y1;
	double		row_distance;
	double		floor_step_x;
	double		floor_step_y;
	double		floor_x;
	double		floor_y;
	int			p;
	int			tex_x;
	int			tex_y;
	int			color;
}				t_floor_ceiling;

typedef struct s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
	int			space;
}				t_keys;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			old_x;
	Display		*display;
	int			loop;
	float		move_speed;
	int			frame;
	int			frame_counter;
	void		*sprite_w[6];
	char		*sprite_addr_w[6];
	void		*sprite_d[6];
	char		*sprite_addr_d[6];
	void		*sprite_a[6];
	char		*sprite_addr_a[6];
	void		*sprite_s[6];
	char		*sprite_addr_s[6];
	int			sprite_wi;
	int			sprint;
	int			sprite_h;
	int			sprite_bpp;
	int			sprite_line_len;
	int			sprite_endian;
	int			old_y;
	t_img		img;
	t_img		textures[11];
	t_config	config;
	t_map		map;
	t_player	player;
	t_ray		ray;
	t_keys		keys;
}				t_data;

void			interact_door(t_data *data);

int				parse_file(char *filepath, t_data *data);

int				parse_texture(char *line, t_config *config, int index);

int				parse_color(char *line, t_color *color);

int				parse_map(int fd, char *first_line, t_map *map);
void			handle_keypress_2(int keycode, t_data *data);
int				handle_keypress(int keycode, t_data *data);
int				handle_keyrelease(int keycode, t_data *data);
int				handle_close(t_data *data);
void			set_player_spawn_2(t_player *player, char dir);
int				extract_player(t_map *map, t_player *player);
void			extract_player_2(t_map *map, t_player *player, int x, int y);

int				validate_map(t_map *map, t_player *player);
void			set_player_spawn(t_player *player, int x, int y, char dir);

int				is_empty_line(char *line);
char			*skip_spaces(char *str);
int				check_extension(char *filename, char *ext);

void			draw_minimap(t_data *data);

void			debug_print_parsing(t_data *data);

int				init_data(t_data *data);
int				init_textures(t_data *data);
int				init_sprite_w(t_data *data);
int				init_sprite_d(t_data *data);
int				init_sprite_a(t_data *data);
int				init_sprite_s(t_data *data);
int				character_rander_loop(t_data *data, char **sprite_addr);
int				character_rander(t_data *data, char **sprite_addr);

void			perform_raycasting(t_data *data);
void			init_ray(t_data *data, t_ray *ray, int x);
void			calculate_step_and_side_dist(t_data *data, t_ray *ray);

void			perform_dda(t_data *data, t_ray *ray);

void			draw_column(t_data *data, t_ray *ray, int x);
void			put_pixel(t_img *img, int x, int y, int color);

void			move_forward(t_data *data);
void			move_backward(t_data *data);
void			strafe_left(t_data *data);
void			strafe_right(t_data *data);

void			rotate_left(t_data *data);
void			rotate_right(t_data *data);

void			setup_hooks(t_data *data);

void			print_error(char *msg);
void			free_all(t_data *data);
void			free_map(char **grid, int height);
void			free_config(t_config *config);
void			free_textures(t_data *data);
void			render_floor_ceiling(t_data *data);

#endif