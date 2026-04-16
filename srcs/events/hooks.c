/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 19:49:25 by aronnet           #+#    #+#             */
/*   Updated: 2026/04/07 21:47:58 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_keypress_2(int keycode, t_data *data)
{
	if (keycode == KEY_LEFT)
		data->keys.left = 1;
	if (keycode == KEY_RIGHT)
		data->keys.right = 1;
	if (keycode == 65505)
	{
		data->sprint = 1;
		data->frame = 3;
		data->move_speed = 0.15;
	}
	if (keycode == KEY_SPACE)
		data->keys.space = 1;
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		XAutoRepeatOn(data->display);
		free_all(data);
		exit(0);
	}
	if (keycode == KEY_W)
		data->keys.w = 1;
	if (keycode == KEY_S)
		data->keys.s = 1;
	if (keycode == KEY_A)
		data->keys.a = 1;
	if (keycode == KEY_D)
		data->keys.d = 1;
	handle_keypress_2(keycode, data);
	return (0);
}

int	handle_keyrelease(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->keys.w = 0;
	if (keycode == KEY_S)
		data->keys.s = 0;
	if (keycode == KEY_A)
		data->keys.a = 0;
	if (keycode == KEY_D)
		data->keys.d = 0;
	if (keycode == KEY_LEFT)
		data->keys.left = 0;
	if (keycode == KEY_RIGHT)
		data->keys.right = 0;
	if (keycode == 65505)
	{
		data->sprint = 0;
		data->frame = 0;
		data->move_speed = MOVE_SPEED;
	}
	return (0);
}

int	handle_close(t_data *data)
{
	XAutoRepeatOn(data->display);
	free_all(data);
	exit(0);
	return (0);
}
