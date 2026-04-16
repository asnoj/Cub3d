/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 04:35:47 by aronnet           #+#    #+#             */
/*   Updated: 2026/03/30 01:20:23 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_run_a(t_data *data)
{
	data->sprite_a[3] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite_anim_04.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_a[3])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_a[3] = mlx_get_data_addr(data->sprite_a[3],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	data->sprite_a[4] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite_anim_05.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_a[4])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_a[4] = mlx_get_data_addr(data->sprite_a[4],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	data->sprite_a[5] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite_anim_06.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_a[5])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_a[5] = mlx_get_data_addr(data->sprite_a[5],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	return (SUCCESS);
}

int	init_sprite_a(t_data *data)
{
	data->sprite_a[0] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite_anim_01.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_a[0])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_a[0] = mlx_get_data_addr(data->sprite_a[0],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	data->sprite_a[1] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite_anim_02.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_a[1])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_a[1] = mlx_get_data_addr(data->sprite_a[1],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	data->sprite_a[2] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite_anim_03.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_a[2])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_a[2] = mlx_get_data_addr(data->sprite_a[2],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	return (init_run_a(data));
}

int	init_run_s(t_data *data)
{
	data->sprite_s[3] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite_anim_16.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_s[3])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_s[3] = mlx_get_data_addr(data->sprite_s[3],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	data->sprite_s[4] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite_anim_17.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_s[4])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_s[4] = mlx_get_data_addr(data->sprite_s[4],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	data->sprite_s[5] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite_anim_18.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_s[5])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_s[5] = mlx_get_data_addr(data->sprite_s[5],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	return (SUCCESS);
}

int	init_sprite_s(t_data *data)
{
	data->sprite_s[0] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite_anim_13.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_s[0])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_s[0] = mlx_get_data_addr(data->sprite_s[0],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	data->sprite_s[1] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite_anim_14.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_s[1])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_s[1] = mlx_get_data_addr(data->sprite_s[1],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	data->sprite_s[2] = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprite_anim_15.xpm", &data->sprite_wi, &data->sprite_h);
	if (!data->sprite_s[2])
		return (print_error("Error: sprite.xpm not found\n"), FAILURE);
	data->sprite_addr_s[2] = mlx_get_data_addr(data->sprite_s[2],
			&data->sprite_bpp, &data->sprite_line_len, &data->sprite_endian);
	return (init_run_s(data));
}
