/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:59:58 by aronnet           #+#    #+#             */
/*   Updated: 2026/04/07 19:00:00 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extension(char *filename, char *ext)
{
	int	len_file;
	int	len_ext;

	len_file = ft_strlen(filename);
	len_ext = ft_strlen(ext);
	if (len_file <= len_ext)
		return (FAILURE);
	if (ft_strncmp(filename + len_file - len_ext, ext, len_ext + 1) != 0)
		return (FAILURE);
	return (SUCCESS);
}

int	parse_element_line(char *line, t_config *config)
{
	char	*trimmed;

	trimmed = skip_spaces(line);
	if (ft_strncmp(trimmed, "NO ", 3) == 0)
		return (parse_texture(trimmed + 3, config, TEX_NO));
	else if (ft_strncmp(trimmed, "SO ", 3) == 0)
		return (parse_texture(trimmed + 3, config, TEX_SO));
	else if (ft_strncmp(trimmed, "WE ", 3) == 0)
		return (parse_texture(trimmed + 3, config, TEX_WE));
	else if (ft_strncmp(trimmed, "EA ", 3) == 0)
		return (parse_texture(trimmed + 3, config, TEX_EA));
	else if (ft_strncmp(trimmed, "F ", 2) == 0)
		return (parse_color(trimmed + 2, &config->floor));
	else if (ft_strncmp(trimmed, "C ", 2) == 0)
		return (parse_color(trimmed + 2, &config->ceiling));
	return (0);
}

static int	parse_elements(int fd, t_config *config, char **first_map_line)
{
	char	*line;
	int		count;
	int		ret;

	count = 0;
	*first_map_line = NULL;
	while (count < NB_ELEMENTS)
	{
		line = get_next_line(fd);
		if (!line)
			return (print_error(ERR_MISS_ELEM), FAILURE);
		if (is_empty_line(line))
		{
			free(line);
			continue ;
		}
		ret = parse_element_line(line, config);
		if (ret == -1)
			return (free(line), FAILURE);
		if (ret == 0)
			return (free(line), print_error(ERR_MISS_ELEM), FAILURE);
		free(line);
		count++;
	}
	return (SUCCESS);
}

static int	find_map_start(int fd, char **first_map_line)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (print_error(ERR_MAP_EMPTY), FAILURE);
		if (!is_empty_line(line))
		{
			*first_map_line = line;
			return (SUCCESS);
		}
		free(line);
	}
}

int	parse_file(char *filepath, t_data *data)
{
	int		fd;
	char	*first_map_line;

	if (check_extension(filepath, ".cub") == FAILURE)
		return (print_error(ERR_EXT), FAILURE);
	fd = open(filepath, O_RDONLY);
	printf("Parsing file: %d\n", fd);
	if (fd < 0)
		return (print_error(ERR_OPEN), FAILURE);
	ft_memset(&data->config, 0, sizeof(t_config));
	ft_memset(&data->map, 0, sizeof(t_map));
	ft_memset(&data->player, 0, sizeof(t_player));
	first_map_line = NULL;
	if (parse_elements(fd, &data->config, &first_map_line) == FAILURE)
		return (close(fd), FAILURE);
	if (find_map_start(fd, &first_map_line) == FAILURE)
		return (close(fd), FAILURE);
	if (parse_map(fd, first_map_line, &data->map) == FAILURE)
		return (close(fd), FAILURE);
	if (validate_map(&data->map, &data->player) == FAILURE)
		return (close(fd), FAILURE);
	close(fd);
	return (SUCCESS);
}
