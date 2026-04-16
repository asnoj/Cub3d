/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 00:52:17 by jcrochet          #+#    #+#             */
/*   Updated: 2026/03/30 00:55:42 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(char **grid, int height)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (i < height)
	{
		if (grid[i])
			free(grid[i]);
		i++;
	}
	free(grid);
}

void	free_config(t_config *config)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (config->tex_path[i])
		{
			free(config->tex_path[i]);
			config->tex_path[i] = NULL;
		}
		i++;
	}
}

void	free_sprites(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (data->sprite_w[i])
			mlx_destroy_image(data->mlx, data->sprite_w[i]);
		if (data->sprite_a[i])
			mlx_destroy_image(data->mlx, data->sprite_a[i]);
		if (data->sprite_s[i])
			mlx_destroy_image(data->mlx, data->sprite_s[i]);
		if (data->sprite_d[i])
			mlx_destroy_image(data->mlx, data->sprite_d[i]);
		i++;
	}
}

void	free_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (data->textures[i].img_ptr)
		{
			mlx_destroy_image(data->mlx, data->textures[i].img_ptr);
			data->textures[i].img_ptr = NULL;
		}
		i++;
	}
}

void	free_all(t_data *data)
{
	if (!data)
		return ;
	free_config(&data->config);
	free_map(data->map.grid, data->map.height);
	if (data->display)
		XCloseDisplay(data->display);
	if (data->mlx)
	{
		free_textures(data);
		free_sprites(data);
		if (data->img.img_ptr)
			mlx_destroy_image(data->mlx, data->img.img_ptr);
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
