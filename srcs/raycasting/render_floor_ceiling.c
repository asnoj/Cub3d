/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor_ceiling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:13:04 by aronnet           #+#    #+#             */
/*   Updated: 2026/04/07 19:13:10 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_tex_pixel(t_img *tex, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	pixel = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(int *)pixel);
}

void	init_floor_ceiling(t_floor_ceiling *data)
{
	data->x = 0;
	data->cell_x = 0;
	data->cell_y = 0;
	data->ceil_idx = 0;
	data->ray_dir_x0 = 0;
	data->ray_dir_y0 = 0;
	data->ray_dir_x1 = 0;
	data->ray_dir_y1 = 0;
	data->row_distance = 0;
	data->floor_step_x = 0;
	data->floor_step_y = 0;
	data->floor_x = 0;
	data->floor_y = 0;
	data->p = 0;
	data->tex_x = 0;
	data->tex_y = 0;
	data->color = 0;
	data->y = 0;
}

void	render_utils(t_floor_ceiling *ceiling, t_data *data)
{
	ceiling->ray_dir_x0 = data->player.dir_x - data->player.plane_x;
	ceiling->ray_dir_y0 = data->player.dir_y - data->player.plane_y;
	ceiling->ray_dir_x1 = data->player.dir_x + data->player.plane_x;
	ceiling->ray_dir_y1 = data->player.dir_y + data->player.plane_y;
	ceiling->p = ceiling->y - WIN_HEIGHT / 2;
	ceiling->row_distance = (0.5 * WIN_HEIGHT) / ceiling->p;
	ceiling->floor_step_x = ceiling->row_distance * (ceiling->ray_dir_x1
			- ceiling->ray_dir_x0) / WIN_WIDTH;
	ceiling->floor_step_y = ceiling->row_distance * (ceiling->ray_dir_y1
			- ceiling->ray_dir_y0) / WIN_WIDTH;
	ceiling->floor_x = data->player.pos_x + ceiling->row_distance
		* ceiling->ray_dir_x0;
	ceiling->floor_y = data->player.pos_y + ceiling->row_distance
		* ceiling->ray_dir_y0;
	ceiling->x = 0;
}

void	render_utils_2(t_floor_ceiling *ceiling, t_img *floor_tex, t_data *data)
{
	ceiling->cell_x = (int)ceiling->floor_x;
	ceiling->cell_y = (int)ceiling->floor_y;
	ceiling->tex_x = (int)(floor_tex->width * (ceiling->floor_x
				- floor(ceiling->floor_x)));
	ceiling->tex_y = (int)(floor_tex->height * (ceiling->floor_y
				- floor(ceiling->floor_y)));
	if (ceiling->tex_x < 0)
		ceiling->tex_x = 0;
	if (ceiling->tex_y < 0)
		ceiling->tex_y = 0;
	ceiling->color = get_tex_pixel(floor_tex, ceiling->tex_x, ceiling->tex_y);
	put_pixel(&data->img, ceiling->x, ceiling->y, ceiling->color);
	ceiling->ceil_idx = TEX_CEIL + ((ceiling->cell_x * 7 + ceiling->cell_y * 13)
			% NB_CEIL_TEX);
	ceiling->color = get_tex_pixel(&data->textures[ceiling->ceil_idx],
			ceiling->tex_x, ceiling->tex_y);
	put_pixel(&data->img, ceiling->x, WIN_HEIGHT - 1 - ceiling->y,
		ceiling->color);
	ceiling->floor_x += ceiling->floor_step_x;
	ceiling->floor_y += ceiling->floor_step_y;
	ceiling->x++;
}

void	render_floor_ceiling(t_data *data)
{
	t_floor_ceiling	*ceiling;
	t_img			*floor_tex;

	ceiling = malloc(sizeof(t_floor_ceiling));
	init_floor_ceiling(ceiling);
	floor_tex = &data->textures[TEX_FLOOR];
	ceiling->y = WIN_HEIGHT / 2 + 1;
	while (ceiling->y < WIN_HEIGHT)
	{
		render_utils(ceiling, data);
		while (ceiling->x < WIN_WIDTH)
			render_utils_2(ceiling, floor_tex, data);
		ceiling->y++;
	}
	free(ceiling);
}
