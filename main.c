/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:22:10 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/11/05 15:22:46 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "src/so_long.h"

#define WIDTH 524
#define HEIGHT 524

static mlx_image_t* image;

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 12 | g << 8 | b << 4 | a);
}

void	ft_randomize(void* param)
{
	(void)param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void	ft_hook(void* param)
{
	t_solong *so_long = (t_solong*)param;

	if (mlx_is_key_down(so_long->init, MLX_KEY_ESCAPE))
		mlx_close_window(so_long->init);
	if (mlx_is_key_down(so_long->init, MLX_KEY_UP))
		so_long->img_player->instances[0].y -= 5;
	if (mlx_is_key_down(so_long->init, MLX_KEY_DOWN))
		so_long->img_player->instances[0].y += 5;
	if (mlx_is_key_down(so_long->init, MLX_KEY_LEFT))
		so_long->img_player->instances[0].x -= 5;
	if (mlx_is_key_down(so_long->init, MLX_KEY_RIGHT))
		so_long->img_player->instances[0].x += 5;
}

void	ft_check_so_long(t_solong *so_long, char *file)
{
	if (!ft_check_file(file))
		ft_error("Error: Invalid file extension");
	init_so_long(so_long);
	if (!ft_check_map_size(so_long, file))
		ft_error("Error: Invalid map size");
	load_map(so_long, file);
	if (!ft_check_correct_characters(so_long))
		ft_error("Error: Characters not allowed");
	if (!ft_check_walls(so_long))
		ft_error("Error: It's not surrounded by walls");
	player_position(so_long);
	if (so_long->x == -1 && so_long->y == -1)
		ft_error("Error: Player position not found");
	//flood_fill(so_long, so_long->x, so_long->y);
	/*if (!access_check(so_long))
		ft_error("Error: No access");*/
}

int	passable_box(t_solong *so_long, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= so_long->width || new_y < 0 || new_y >= so_long->height)
		return (0);
	if (so_long->map[new_y][new_x] != '1')
	{
		so_long->x = new_x;
		so_long->y = new_y;
		return (1);
	}
	return (0);
}

int32_t main(int argc, char **argv)
{
	t_solong	so_long;
	mlx_t		*init;
	//int			i;

	if (argc != 2)
	{
		ft_error("Usage: ./so_long <map_file>");
		return (EXIT_FAILURE);
	}
	init_so_long(&so_long);
	ft_check_so_long(&so_long, argv[1]);
	load_map(&so_long, argv[1]);
	//map_elements(&so_long);
	duplicated_map(&so_long);
	flood_fill(&so_long, so_long.x, so_long.y);
		printf("flood fill");
	if (!access_check(&so_long))
	{
		printf("acces check in '\n'");
		clean_(&so_long);
		printf("acces check in clean '\n'");
		return (EXIT_FAILURE);
	}
	printf("El mapa esta bien\n");
 	init = mlx_init(1028, 1028, "so_long", true);
	if (!init)
	{
		ft_error("Error: Failed to initialize MLX");
		return(EXIT_FAILURE);
	}
	printf("El so_long inicia bien\n");
	mlx_loop(init);
	/*
	ft_mlx_init(&so_long);
 	mlx_key_hook(so_long.init, ft_moves, &so_long);
	mlx_loop_hook(so_long.init, ft_hook, &so_long);
	mlx_loop(so_long.init);
 	mlx_terminate(so_long.init);

	if (so_long.txt_coin)
		mlx_delete_texture(so_long.txt_coin);
	if (so_long.txt_exit)
		mlx_delete_texture(so_long.txt_exit);
	if (so_long.txt_player)
		mlx_delete_texture(so_long.txt_player);
	if (so_long.txt_wall)
		mlx_delete_texture(so_long.txt_wall);
	if (so_long.txt_floor)
		mlx_delete_texture(so_long.txt_floor);

	i = 0;
	while (i < so_long.height)
	{
		free(so_long.map[i]);
		free(so_long.dup[i]);
		i++;
	} 
	free(so_long.map);
	free(so_long.dup);

	clean_(&so_long);*/
	return (EXIT_SUCCESS);
}
