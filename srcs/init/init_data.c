/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:53:46 by aronnet           #+#    #+#             */
/*   Updated: 2026/04/07 18:53:48 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data_utils(t_data *data)
{
	data->old_x = 0;
	data->frame = 0;
	data->sprint = 0;
	data->frame_counter = 0;
	data->loop = 0;
	data->old_y = 0;
	data->move_speed = MOVE_SPEED;
	data->display = XOpenDisplay(NULL);
}

int	init_data(t_data *data)
{
	init_data_utils(data);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (print_error(ERR_MLX_INIT), FAILURE);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!data->win)
		return (print_error(ERR_MLX_WIN), FAILURE);
	data->img.img_ptr = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.img_ptr)
		return (print_error(ERR_MLX_IMG), FAILURE);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	data->img.width = WIN_WIDTH;
	data->img.height = WIN_HEIGHT;
	if (init_textures(data) == FAILURE)
		return (FAILURE);
	if (init_sprite_w(data) || init_sprite_a(data) || init_sprite_s(data)
		|| init_sprite_d(data))
		return (FAILURE);
	return (SUCCESS);
}
