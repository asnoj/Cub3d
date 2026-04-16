/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 02:30:41 by jcrochet          #+#    #+#             */
/*   Updated: 2026/04/07 18:50:46 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	interact_door(t_data *data)
{
	int	x;
	int	y;
	int	target_x;
	int	target_y;

	x = (int)data->player.pos_x;
	y = (int)data->player.pos_y;
	target_x = (int)(data->player.pos_x + data->player.dir_x);
	target_y = (int)(data->player.pos_y + data->player.dir_y);
	if (target_x == x && target_y == y)
		return ;
	if (data->map.grid[target_y][target_x] == 'D')
		data->map.grid[target_y][target_x] = 'O';
	else if (data->map.grid[target_y][target_x] == 'O')
		data->map.grid[target_y][target_x] = 'D';
}
