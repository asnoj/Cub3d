/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:51:43 by aronnet           #+#    #+#             */
/*   Updated: 2026/04/07 18:51:45 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_walkable(t_data *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_y < 0 || map_y >= data->map.height)
		return (0);
	if (map_x < 0 || map_x >= (int)ft_strlen(data->map.grid[map_y]))
		return (0);
	if (data->map.grid[map_y][map_x] == '1'
		|| data->map.grid[map_y][map_x] == 'D')
		return (0);
	return (1);
}

void	move_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_x * data->move_speed;
	new_y = data->player.pos_y + data->player.dir_y * data->move_speed;
	if (is_walkable(data, new_x, data->player.pos_y))
		data->player.pos_x = new_x;
	if (is_walkable(data, data->player.pos_x, new_y))
		data->player.pos_y = new_y;
}

void	move_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_x * data->move_speed;
	new_y = data->player.pos_y - data->player.dir_y * data->move_speed;
	if (is_walkable(data, new_x, data->player.pos_y))
		data->player.pos_x = new_x;
	if (is_walkable(data, data->player.pos_x, new_y))
		data->player.pos_y = new_y;
}

void	strafe_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.plane_x * data->move_speed;
	new_y = data->player.pos_y - data->player.plane_y * data->move_speed;
	if (is_walkable(data, new_x, data->player.pos_y))
		data->player.pos_x = new_x;
	if (is_walkable(data, data->player.pos_x, new_y))
		data->player.pos_y = new_y;
}

void	strafe_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.plane_x * data->move_speed;
	new_y = data->player.pos_y + data->player.plane_y * data->move_speed;
	if (is_walkable(data, new_x, data->player.pos_y))
		data->player.pos_x = new_x;
	if (is_walkable(data, data->player.pos_x, new_y))
		data->player.pos_y = new_y;
}
