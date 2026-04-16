/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:13:25 by aronnet           #+#    #+#             */
/*   Updated: 2026/04/07 19:15:19 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_texture_index(t_ray *ray)
{
	if (ray->is_door == 1)
		return (TEX_DOOR);
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			return (TEX_WE);
		return (TEX_EA);
	}
	if (ray->dir_y < 0)
		return (TEX_NO);
	return (TEX_SO);
}

static void	calculate_tex_x(t_data *data, t_ray *ray, t_tex_info *tex)
{
	t_img	*texture;

	texture = &data->textures[tex->tex_index];
	if (ray->side == 0)
		ray->wall_x = data->player.pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = data->player.pos_x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	tex->tex_x = (int)(ray->wall_x * texture->width);
	if ((ray->side == 0 && ray->dir_x > 0) || (ray->side == 1
			&& ray->dir_y < 0))
		tex->tex_x = texture->width - tex->tex_x - 1;
}

static int	get_tex_color(t_img *tex, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	pixel = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(int *)pixel);
}

void	verif_ray(t_ray *ray)
{
	if (ray->draw_start < 0)
		ray->draw_start = 0;
}

void	draw_column(t_data *data, t_ray *ray, int x)
{
	t_tex_info	tex;
	t_img		*texture;
	int			y;
	int			color;

	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	verif_ray(ray);
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
	tex.tex_index = get_texture_index(ray);
	calculate_tex_x(data, ray, &tex);
	texture = &data->textures[tex.tex_index];
	tex.step = (double)texture->height / (double)ray->line_height;
	tex.tex_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2)
		* tex.step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex.tex_y = (int)tex.tex_pos & (texture->height - 1);
		tex.tex_pos += tex.step;
		color = get_tex_color(texture, tex.tex_x, tex.tex_y);
		put_pixel(&data->img, x, y++, color);
	}
}
