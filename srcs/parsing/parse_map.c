/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 00:48:31 by jcrochet          #+#    #+#             */
/*   Updated: 2026/03/23 00:54:45 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	strip_newline(char *line)
{
	int	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

static char	**append_line(char **grid, char *line, int height)
{
	char	**new_grid;
	int		i;

	new_grid = malloc(sizeof(char *) * (height + 2));
	if (!new_grid)
		return (NULL);
	i = 0;
	while (i < height)
	{
		new_grid[i] = grid[i];
		i++;
	}
	new_grid[i] = line;
	new_grid[i + 1] = NULL;
	if (grid)
		free(grid);
	return (new_grid);
}

static int	calculate_width(char **grid, int height)
{
	int	width;
	int	len;
	int	i;

	width = 0;
	i = 0;
	while (i < height)
	{
		len = ft_strlen(grid[i]);
		if (len > width)
			width = len;
		i++;
	}
	return (width);
}

static int	check_empty_lines_in_map(char **grid, int height)
{
	int	i;
	int	last_non_empty;

	last_non_empty = height - 1;
	while (last_non_empty >= 0 && is_empty_line(grid[last_non_empty]))
		last_non_empty--;
	i = 0;
	while (i <= last_non_empty)
	{
		if (is_empty_line(grid[i]))
			return (print_error(ERR_MAP_EMPTY), FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	parse_map(int fd, char *first_map_line, t_map *map)
{
	char	*line;

	strip_newline(first_map_line);
	map->grid = NULL;
	map->height = 0;
	map->grid = append_line(map->grid, first_map_line, map->height);
	if (!map->grid)
		return (print_error(ERR_MALLOC), FAILURE);
	map->height = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		strip_newline(line);
		map->grid = append_line(map->grid, line, map->height);
		if (!map->grid)
			return (print_error(ERR_MALLOC), FAILURE);
		map->height++;
	}
	if (check_empty_lines_in_map(map->grid, map->height) == FAILURE)
		return (FAILURE);
	map->width = calculate_width(map->grid, map->height);
	return (SUCCESS);
}
