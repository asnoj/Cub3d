/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 23:04:35 by jcrochet          #+#    #+#             */
/*   Updated: 2026/04/07 18:58:23 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_SCALE)
	{
		j = 0;
		while (j < MINIMAP_SCALE)
		{
			put_pixel(&data->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
	i++;
}

static void	draw_square_player(t_data *data)
{
	int	y;
	int	x;

	x = (int)data->player.pos_x;
	y = (int)data->player.pos_y;
	draw_square(data, x * MINIMAP_SCALE, y * MINIMAP_SCALE, 0xFF0000);
}

static int	find_x(char *s)
{
	int	x;

	x = 0;
	while (s[x] && s[x] != '1' && s[x] != 'D')
	{
		x++;
	}
	return (x);
}

void	draw_minimap(t_data *data)
{
	int		x;
	int		y;
	int		color;
	t_map	*map;

	map = &data->map;
	y = 0;
	while (y < map->height)
	{
		x = find_x(map->grid[y]);
		while (x < (int)ft_strlen(map->grid[y]))
		{
			if (map->grid[y][x] == '1')
				color = 0xFFFFFF;
			else if (map->grid[y][x] == 'D')
				color = 0x00FF00;
			else if (map->grid[y][x] == '0' || map->grid[y][x] == 'O')
				color = 0x000000;
			draw_square(data, x * MINIMAP_SCALE, y * MINIMAP_SCALE, color);
			x++;
		}
		y++;
	}
	draw_square_player(data);
}
