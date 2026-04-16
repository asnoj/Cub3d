/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:00:20 by aronnet           #+#    #+#             */
/*   Updated: 2026/04/07 19:05:32 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_one_value(char **str, int *value)
{
	char	*s;
	int		result;
	int		has_digit;

	s = skip_spaces(*str);
	result = 0;
	has_digit = 0;
	if (*s == '+')
		s++;
	if (*s == '-')
		return (FAILURE);
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
		if (result > 255)
			return (FAILURE);
		has_digit = 1;
		s++;
	}
	if (!has_digit || (*s != ',' && *s != '\0' && *s != '\n' && *s != ' '
			&& *s != '\t'))
		return (FAILURE);
	*value = result;
	*str = s;
	return (SUCCESS);
}

static int	check_trailing(char *str)
{
	char	*s;

	s = skip_spaces(str);
	if (*s == '\0' || *s == '\n')
		return (SUCCESS);
	return (FAILURE);
}

static int	skip_comma(char **str)
{
	char	*s;

	s = skip_spaces(*str);
	if (*s != ',')
		return (FAILURE);
	s++;
	*str = s;
	return (SUCCESS);
}

int	parse_color(char *line, t_color *color)
{
	char	*str;
	int		r;
	int		g;
	int		b;

	if (color->is_set)
		return (print_error(ERR_DUP_ELEM), -1);
	str = line;
	if (parse_one_value(&str, &r) == FAILURE || skip_comma(&str) == FAILURE)
		return (print_error(ERR_COLOR_FMT), -1);
	if (parse_one_value(&str, &g) == FAILURE)
		return (print_error(ERR_COLOR_FMT), -1);
	if (skip_comma(&str) == FAILURE)
		return (print_error(ERR_COLOR_FMT), -1);
	if (parse_one_value(&str, &b) == FAILURE)
		return (print_error(ERR_COLOR_FMT), -1);
	if (check_trailing(str) == FAILURE)
		return (print_error(ERR_COLOR_FMT), -1);
	color->r = r;
	color->g = g;
	color->b = b;
	color->hex = (r << 16) | (g << 8) | b;
	color->is_set = 1;
	return (1);
}
