/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:39:18 by pablogon          #+#    #+#             */
/*   Updated: 2024/11/25 15:13:00 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_game(t_so_long *game, char *file)
{
	if (!ft_check_file(file))
		ft_error("Error: Invalid file extension");
	ft_init_game(game);
	if (!ft_check_map_size(game, file))
		ft_error("Error: Invalid map size");
	ft_load_map(game, file);
	if (!ft_check_correct_characters(game))
		ft_error("Error: Characters not allowed");
	if (!ft_check_walls(game))
		ft_error("Error: It's not surrounded by walls");
	ft_duplicate_map(game);
	ft_get_player_position(game);
	if (game->x == -1 && game->y == -1)
		ft_error("Error: Player position not found");
	flood_fill(game, game->x, game->y);
	if (!ft_check_access(game))
		ft_error("Error: No access");
}

int	main(int argc, char **argv)
{
	t_so_long	game;

	if (argc != 2)
		ft_error("ERROR: Invalid number of arguments");
	ft_check_game(&game, argv[1]);
	ft_mlx_init(&game);
	ft_cleanup(&game);
	return (0);
}
