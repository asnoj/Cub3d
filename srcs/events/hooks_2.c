/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:54:18 by aronnet           #+#    #+#             */
/*   Updated: 2026/04/07 19:29:15 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	game_loop_2(t_data *data)
{
	if (data->keys.w)
		character_rander_loop(data, data->sprite_addr_w);
	else if (data->keys.s)
		character_rander_loop(data, data->sprite_addr_s);
	else if (data->keys.a)
		character_rander_loop(data, data->sprite_addr_a);
	else if (data->keys.d)
		character_rander_loop(data, data->sprite_addr_d);
	else
		character_rander(data, data->sprite_addr_w);
}

static int	game_loop(t_data *data)
{
	if (data->keys.space)
	{
		interact_door(data);
		data->keys.space = 0;
	}
	if (data->keys.w >= 1)
		move_forward(data);
	if (data->keys.s)
		move_backward(data);
	if (data->keys.a)
		strafe_left(data);
	if (data->keys.d)
		strafe_right(data);
	if (data->keys.left)
		rotate_left(data);
	if (data->keys.right)
		rotate_right(data);
	render_floor_ceiling(data);
	perform_raycasting(data);
	draw_minimap(data);
	game_loop_2(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}

int	camera_track(int x, int y, t_data *data)
{
	int	center_x;

	(void)y;
	center_x = WIN_WIDTH / 2;
	if (x == center_x)
		return (0);
	if (x < center_x)
		rotate_left(data);
	else
		rotate_right(data);
	mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	data->old_x = WIN_WIDTH / 2;
	data->old_y = WIN_HEIGHT / 2;
	return (0);
}

void	setup_hooks(t_data *data)
{
	XAutoRepeatOff(data->display);
	mlx_hook(data->win, ON_KEYDOWN, 1L << 0, handle_keypress, data);
	mlx_hook(data->win, ON_KEYUP, 1L << 1, handle_keyrelease, data);
	mlx_hook(data->win, ON_DESTROY, 0, handle_close, data);
	mlx_hook(data->win, 6, 1L << 6, camera_track, data);
	mlx_mouse_hide(data->mlx, data->win);
	mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	mlx_loop_hook(data->mlx, game_loop, data);
}
