/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 22:57:30 by jcrochet          #+#    #+#             */
/*   Updated: 2026/03/30 01:09:45 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Fonction pour skip les espaces/tabs
// Fonction pour vérifier si une ligne est vide
// Fonction ft_atoi sécurisée (qui détecte les overflows)
// Fonction pour vérifier l'extension .cub
// Fonction pour trim une ligne (retirer \n en fin)

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

// void	free_map(char **grid, int height)
//{
//	int	i;

//	if (!grid)
//		return ;
//	i = 0;
//	while (i < height)
//	{
//		free(grid[i]);
//		i++;
//	}
//	free(grid);
//}

int	is_valid_map_char(char c)
{
	if (c == '0' || c == '1' || c == ' ' || c == 'D' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W')
		return (1);
	return (0);
}

char	*skip_spaces(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}
