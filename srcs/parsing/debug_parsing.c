/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronnet <aronnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:59:18 by aronnet           #+#    #+#             */
/*   Updated: 2026/04/07 18:59:20 by aronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"

//static void	debug_print_separator(char *title)
//{
//	printf("\n");
//	printf("╔══════════════════════════════════════════════╗\n");
//	printf("║  %-44s║\n", title);
//	printf("╚══════════════════════════════════════════════╝\n");
//}

//static void	debug_print_config(t_config *config)
//{
//	debug_print_separator("CONFIG — Textures & Colors");
//	printf("\n");
//	printf("  Textures paths:\n");
//	printf("  ┌────────┬──────────────────────────────────┐\n");
//	printf("  │ NO     │ %s\n", config->tex_path[TEX_NO]
//		? config->tex_path[TEX_NO] : "(null)");
//	printf("  │ SO     │ %s\n", config->tex_path[TEX_SO]
//		? config->tex_path[TEX_SO] : "(null)");
//	printf("  │ WE     │ %s\n", config->tex_path[TEX_WE]
//		? config->tex_path[TEX_WE] : "(null)");
//	printf("  │ EA     │ %s\n", config->tex_path[TEX_EA]
//		? config->tex_path[TEX_EA] : "(null)");
//	printf("  └────────┴──────────────────────────────────┘\n");
//	printf("\n");
//	printf("  Colors:\n");
//	printf("  ┌─────────┬─────┬─────┬─────┬────────────┬────────┐\n");
//	printf("  │         │  R  │  G  │  B  │    HEX     │ is_set │\n");
//	printf("  ├─────────┼─────┼─────┼─────┼────────────┼────────┤\n");
//	printf("  │ Floor   │ %3d │ %3d │ %3d │ 0x%06X │   %d    │\n",
//		config->floor.r, config->floor.g, config->floor.b,
//		config->floor.hex, config->floor.is_set);
//	printf("  │ Ceiling │ %3d │ %3d │ %3d │ 0x%06X │   %d    │\n",
//		config->ceiling.r, config->ceiling.g, config->ceiling.b,
//		config->ceiling.hex, config->ceiling.is_set);
//	printf("  └─────────┴─────┴─────┴─────┴────────────┴────────┘\n");
//}

//static void	debug_print_player(t_player *player)
//{
//	debug_print_separator("PLAYER — Position & Direction");
//	printf("\n");
//	printf("  Position:\n");
//	printf("    pos_x   = %.2f  (case %d, offset %.2f dans la case)\n",
//		player->pos_x, (int)player->pos_x,
//		player->pos_x - (int)player->pos_x);
//	printf("    pos_y   = %.2f  (case %d, offset %.2f dans la case)\n",
//		player->pos_y, (int)player->pos_y,
//		player->pos_y - (int)player->pos_y);
//	printf("\n");
//	printf("  Direction vector:\n");
//	printf("    dir_x   = %.2f\n", player->dir_x);
//	printf("    dir_y   = %.2f\n", player->dir_y);
//	if (player->dir_x == 0 && player->dir_y == -1)
//		printf("    → Facing NORTH (↑)\n");
//	else if (player->dir_x == 0 && player->dir_y == 1)
//		printf("    → Facing SOUTH (↓)\n");
//	else if (player->dir_x == 1 && player->dir_y == 0)
//		printf("    → Facing EAST (→)\n");
//	else if (player->dir_x == -1 && player->dir_y == 0)
//		printf("    → Facing WEST (←)\n");
//	printf("\n");
//	printf("  Camera plane:\n");
//	printf("    plane_x = %.2f\n", player->plane_x);
//	printf("    plane_y = %.2f\n", player->plane_y);
//	printf("    → FOV ≈ %.0f°\n",
//		atan2(0.66, 1.0) * 2.0 * (180.0 / M_PI));
//}

//static void	debug_print_map(t_map *map, t_player *player)
//{
//	int	x;
//	int	y;
//	int	player_x;
//	int	player_y;

//	player_x = (int)player->pos_x;
//	player_y = (int)player->pos_y;
//	debug_print_separator("MAP — Grid");
//	printf("\n");
//	printf("  Dimensions: %d x %d (width x height)\n",
//		map->width, map->height);
//	printf("\n");
//	printf("     ");
//	x = 0;
//	while (x < map->width && x < 50)
//		printf("%d", (x++) % 10);
//	printf("\n");
//	printf("     ");
//	x = 0;
//	while (x < map->width && x < 50)
//	{
//		printf("─");
//		x++;
//	}
//	printf("\n");
//	y = 0;
//	while (y < map->height)
//	{
//		printf("  %2d│", y);
//		x = 0;
//		while (map->grid[y][x])
//		{
//			if (x == player_x && y == player_y)
//				printf("\033[1;32mP\033[0m");
//			else if (map->grid[y][x] == '1')
//				printf("\033[1;37m█\033[0m");
//			else if (map->grid[y][x] == '0')
//				printf("\033[0;90m·\033[0m");
//			else if (map->grid[y][x] == ' ')
//				printf(" ");
//			else
//				printf("%c", map->grid[y][x]);
//			x++;
//		}
//		printf("\n");
//		y++;
//	}
//	printf("\n");
//	printf("  Légende: \033[1;32mP\033[0m = player  ");
//	printf("\033[1;37m█\033[0m = wall  ");
//	printf("\033[0;90m·\033[0m = empty\n");
//}

///*
//** ══════════════════════════════════════════════════════════════
//** FONCTION PUBLIQUE — à appeler dans main.c après parse_file()
//** ══════════════════════════════════════════════════════════════
//*/
//void	debug_print_parsing(t_data *data)
//{
//	printf("\n");
//	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
//	printf("┃         CUB3D — PARSING DEBUG OUTPUT           ┃\n");
//	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
//	debug_print_config(&data->config);
//	debug_print_player(&data->player);
//	debug_print_map(&data->map, &data->player);
//	printf("\n");
//	printf("═══════════════════════════════════════════════════\n");
//	printf("  ✓ Parsing complete. All data ready for init.\n");
//	printf("═══════════════════════════════════════════════════\n\n");
//}