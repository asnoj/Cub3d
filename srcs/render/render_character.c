/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_character.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 04:38:40 by aronnet           #+#    #+#             */
/*   Updated: 2026/04/01 23:00:02 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	character_rander(t_data *data, char **sprite_addr)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < data->sprite_h)
	{
		x = 0;
		while (x < data->sprite_wi)
		{
			color = *(int *)(sprite_addr[1] + y * data->sprite_line_len + x
					* (data->sprite_bpp / 8));
			if (color != 0x000000)
				*(int *)(data->img.addr + (20 + y) * data->img.line_len + (1160
							+ x) * (data->img.bpp / 8)) = color;
			x++;
		}
		y++;
	}
	return (0);
}

void	sprite_load(t_data *data)
{
	data->frame_counter = 0;
	data->frame++;
	if (data->frame >= 3 && data->sprint != 1)
		data->frame = 0;
	if (data->frame >= 6 && data->sprint == 1)
		data->frame = 3;
}

int	frame_valid(t_data *data)
{
	if (data->frame_counter >= 10 || (data->frame_counter >= 7
			&& data->sprint == 1))
		return (1);
	return (0);
}

int	character_rander_loop(t_data *data, char **sprite_addr)
{
	int		x;
	int		y;
	int		color;
	char	*current_sprite;

	data->frame_counter++;
	if (frame_valid(data))
		sprite_load(data);
	current_sprite = sprite_addr[data->frame];
	y = 0;
	while (y < data->sprite_h)
	{
		x = 0;
		while (x < data->sprite_wi)
		{
			color = *(int *)(current_sprite + y * data->sprite_line_len + x
					* (data->sprite_bpp / 8));
			if (color != 0x000000)
				*(int *)(data->img.addr + (20 + y) * data->img.line_len + (1160
							+ x) * (data->img.bpp / 8)) = color;
			x++;
		}
		y++;
	}
	return (0);
}
