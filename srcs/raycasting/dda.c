/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:08:13 by aronnet           #+#    #+#             */
/*   Updated: 2026/04/07 19:12:31 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	perform_dda_2(t_data *data, t_ray *ray)
{
	if (data->map.grid[ray->map_y][ray->map_x] == 'D')
		ray->is_door = 1;
	ray->hit = 1;
}

void	perform_dda(t_data *data, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y >= 0 && ray->map_y < data->map.height && ray->map_x >= 0
			&& ray->map_x < (int)ft_strlen(data->map.grid[ray->map_y])
			&& (data->map.grid[ray->map_y][ray->map_x] == '1'
			|| data->map.grid[ray->map_y][ray->map_x] == 'D'))
			perform_dda_2(data, ray);
	}
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}
