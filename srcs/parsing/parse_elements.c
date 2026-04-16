/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:05:45 by aronnet           #+#    #+#             */
/*   Updated: 2026/04/07 19:05:47 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*clean_path(char *str)
{
	char	*start;
	char	*result;
	int		len;

	start = skip_spaces(str);
	if (!start || *start == '\0' || *start == '\n')
		return (NULL);
	len = ft_strlen(start);
	while (len > 0 && (start[len - 1] == '\n' || start[len - 1] == ' '
			|| start[len - 1] == '\t'))
		len--;
	if (len <= 0)
		return (NULL);
	result = ft_substr(start, 0, len);
	return (result);
}

static int	check_file_exists(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (FAILURE);
	close(fd);
	return (SUCCESS);
}

int	parse_texture(char *line, t_config *config, int index)
{
	char	*path;

	if (config->tex_path[index] != NULL)
		return (print_error(ERR_DUP_ELEM), -1);
	path = clean_path(line);
	if (!path)
		return (print_error(ERR_INV_ELEM), -1);
	if (check_file_exists(path) == FAILURE)
	{
		print_error(ERR_TEX_LOAD);
		free(path);
		return (-1);
	}
	config->tex_path[index] = path;
	return (1);
}
