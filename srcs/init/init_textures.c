/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:22:16 by aronnet           #+#    #+#             */
/*   Updated: 2026/03/30 16:49:58 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_one_texture(t_data *data, t_img *tex, char *path)
{
	tex->img_ptr = mlx_xpm_file_to_image(data->mlx, path, &tex->width,
			&tex->height);
	if (!tex->img_ptr)
		return (print_error(ERR_TEX_LOAD), FAILURE);
	tex->addr = mlx_get_data_addr(tex->img_ptr, &tex->bpp, &tex->line_len,
			&tex->endian);
	return (SUCCESS);
}

static char	**load_ceil_texture(char **ceil_paths)
{
	ceil_paths[0] = ft_strdup("./textures/ceiling0.xpm");
	ceil_paths[1] = ft_strdup("./textures/ceiling1.xpm");
	ceil_paths[2] = ft_strdup("./textures/ceiling2.xpm");
	ceil_paths[3] = ft_strdup("./textures/ceiling3.xpm");
	ceil_paths[4] = ft_strdup("./textures/ceiling4.xpm");
	ceil_paths[5] = NULL;
	return (ceil_paths);
}

void	free_ceil(char **ceil_paths)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		free(ceil_paths[i]);
		i++;
	}
	free(ceil_paths);
}

int	norm_text(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (load_one_texture(data, &data->textures[i],
				data->config.tex_path[i]) == FAILURE)
			return (FAILURE);
		i++;
	}
	return (0);
}

int	init_textures(t_data *data)
{
	int		i;
	char	**ceil_paths;

	ceil_paths = malloc(sizeof(char *) * 6);
	ceil_paths = load_ceil_texture(ceil_paths);
	if (norm_text(data))
		return (free_ceil(ceil_paths), FAILURE);
	if (load_one_texture(data, &data->textures[TEX_DOOR],
			"./textures/door.xpm") == FAILURE)
		return (free_ceil(ceil_paths), FAILURE);
	if (load_one_texture(data, &data->textures[TEX_FLOOR],
			"./textures/floor.xpm") == FAILURE)
		return (free_ceil(ceil_paths), FAILURE);
	i = 0;
	while (i < NB_CEIL_TEX)
	{
		if (load_one_texture(data, &data->textures[TEX_CEIL + i],
				ceil_paths[i]) == FAILURE)
			return (free_ceil(ceil_paths), FAILURE);
		i++;
	}
	free_ceil(ceil_paths);
	return (SUCCESS);
}
