/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 04:34:54 by aronnet           #+#    #+#             */
/*   Updated: 2026/03/30 01:20:28 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_run_d(t_data *data)
{
	data->sprite_d[3] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite_anim_10.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_d[3])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_d[3] = mlx_get_data_addr(data->sprite_d[3],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	data->sprite_d[4] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite_anim_11.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_d[4])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_d[4] = mlx_get_data_addr(data->sprite_d[4],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	data->sprite_d[5] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite_anim_12.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_d[5])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_d[5] = mlx_get_data_addr(data->sprite_d[5],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	return (SUCCESS);
}

int	init_sprite_d(t_data *data)
{
	data->sprite_d[0] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite_anim_07.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_d[0])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_d[0] = mlx_get_data_addr(data->sprite_d[0],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	data->sprite_d[1] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite_anim_08.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_d[1])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_d[1] = mlx_get_data_addr(data->sprite_d[1],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	data->sprite_d[2] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite_anim_09.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_d[2])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_d[2] = mlx_get_data_addr(data->sprite_d[2],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	return (init_run_d(data));
}

int	init_run_w(t_data *data)
{
	data->sprite_w[3] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_w[3])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_w[3] = mlx_get_data_addr(data->sprite_w[3],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	data->sprite_w[4] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite2.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_w[4])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_w[4] = mlx_get_data_addr(data->sprite_w[4],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	data->sprite_w[5] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite3.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_w[5])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_w[5] = mlx_get_data_addr(data->sprite_w[5],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	return (SUCCESS);
}

int	init_sprite_w(t_data *data)
{
	data->sprite_w[0] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_w[0])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_w[0] = mlx_get_data_addr(data->sprite_w[0],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	data->sprite_w[1] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite2.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_w[1])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_w[1] = mlx_get_data_addr(data->sprite_w[1],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	data->sprite_w[2] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite3.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_w[2])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_w[2] = mlx_get_data_addr(data->sprite_w[2],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	return (init_run_w(data));
}
