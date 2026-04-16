/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:07:57 by aronnet           #+#    #+#             */
/*   Updated: 2026/04/07 19:07:59 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_spawn(t_player *player, int x, int y, char dir)
{
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	if (dir == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else
		set_player_spawn_2(player, dir);
}

static char	**duplicate_grid(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->grid[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static int	flood_fill(char **grid, int height, int x, int y)
{
	if (y < 0 || y >= height)
		return (1);
	if (x < 0 || x >= (int)ft_strlen(grid[y]))
		return (1);
	if (grid[y][x] == ' ')
		return (1);
	if (grid[y][x] == '1' || grid[y][x] == 'V')
		return (0);
	grid[y][x] = 'V';
	if (flood_fill(grid, height, x + 1, y))
		return (1);
	if (flood_fill(grid, height, x - 1, y))
		return (1);
	if (flood_fill(grid, height, x, y + 1))
		return (1);
	if (flood_fill(grid, height, x, y - 1))
		return (1);
	return (0);
}

static int	check_map_closed(t_map *map, t_player *player)
{
	char	**copy;
	int		start_x;
	int		start_y;
	int		result;

	copy = duplicate_grid(map);
	if (!copy)
		return (print_error(ERR_MALLOC), FAILURE);
	start_x = (int)player->pos_x;
	start_y = (int)player->pos_y;
	result = flood_fill(copy, map->height, start_x, start_y);
	free_map(copy, map->height);
	if (result == 1)
		return (print_error(ERR_MAP_CLOSED), FAILURE);
	return (SUCCESS);
}

int	validate_map(t_map *map, t_player *player)
{
	if (extract_player(map, player) == FAILURE)
		return (FAILURE);
	if (check_map_closed(map, player) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
