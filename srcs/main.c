/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 19:48:16 by aronnet           #+#    #+#             */
/*   Updated: 2026/04/01 23:59:54 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//** Le main est simple et linéaire :
//**
//**   1. parse_file()   → lit le .cub, remplit config + map + player
//**   2. init_data()    → lance miniLibX, charge les textures depuis
//**                        les chemins stockés dans config.tex_path[]
//**   3. setup_hooks()  → branche les events clavier + croix rouge
//**   4. mlx_loop()     → boucle infinie du jeu
//**
//** Si le parsing échoue, on ne touche jamais à miniLibX.
//** Si l'init échoue, on free la config et la map avant de quitter.

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		print_error(ERR_ARGS);
		return (FAILURE);
	}
	ft_memset(&data, 0, sizeof(t_data));
	if (parse_file(argv[1], &data) == FAILURE)
	{
		free_config(&data.config);
		free_map(data.map.grid, data.map.height);
		return (FAILURE);
	}
	if (init_data(&data) == FAILURE)
	{
		free_all(&data);
		return (FAILURE);
	}
	setup_hooks(&data);
	mlx_loop(data.mlx);
	free_all(&data);
	return (SUCCESS);
}
