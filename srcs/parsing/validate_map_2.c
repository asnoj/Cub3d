/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:06:59 by aronnet           #+#    #+#             */
/*   Updated: 2026/04/07 19:19:17 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	extract_player_2(t_map *map, t_player *player, int x, int y)
{
	set_player_spawn(player, x, y, map->grid[y][x]);
	map->grid[y][x] = '0';
	player->spawn_count++;
}

int	extract_player(t_map *map, t_player *player)
{
	int	x;
	int	y;

	player->spawn_count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (player->spawn_count > 1)
				return (print_error(ERR_MAP_PLAYER), FAILURE);
			if (!ft_strchr(VALID_MAP_CHARS, map->grid[y][x]))
				return (print_error(ERR_MAP_CHAR), FAILURE);
			if (ft_strchr(SPAWN_CHARS, map->grid[y][x]))
				extract_player_2(map, player, x, y);
			x++;
		}
		y++;
	}
	if (player->spawn_count == 0)
		return (print_error(ERR_MAP_PLAYER), FAILURE);
	return (SUCCESS);
}

void	set_player_spawn_2(t_player *player, char dir)
{
	if (dir == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}
