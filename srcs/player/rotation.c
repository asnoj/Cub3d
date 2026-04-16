/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:50:09 by aronnet           #+#    #+#             */
/*   Updated: 2026/04/07 18:51:24 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cos_a;
	double	sin_a;

	cos_a = cos(-ROT_SPEED);
	sin_a = sin(-ROT_SPEED);
	old_dir_x = data->player.dir_x;
	data->player.dir_x = old_dir_x * cos_a - data->player.dir_y * sin_a;
	data->player.dir_y = old_dir_x * sin_a + data->player.dir_y * cos_a;
	old_plane_x = data->player.plane_x;
	data->player.plane_x = old_plane_x * cos_a - data->player.plane_y * sin_a;
	data->player.plane_y = old_plane_x * sin_a + data->player.plane_y * cos_a;
}

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cos_a;
	double	sin_a;

	cos_a = cos(ROT_SPEED);
	sin_a = sin(ROT_SPEED);
	old_dir_x = data->player.dir_x;
	data->player.dir_x = old_dir_x * cos_a - data->player.dir_y * sin_a;
	data->player.dir_y = old_dir_x * sin_a + data->player.dir_y * cos_a;
	old_plane_x = data->player.plane_x;
	data->player.plane_x = old_plane_x * cos_a - data->player.plane_y * sin_a;
	data->player.plane_y = old_plane_x * sin_a + data->player.plane_y * cos_a;
}
