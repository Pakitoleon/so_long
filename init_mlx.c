/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:42:12 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/09/25 17:50:06 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	ft_mlx_init(t_so_long *so_long)
{
	mlx_set_setting (MLX_STRETCH_IMAGE, true);
	so_long->init = mlx_init(so_long->width * PIXEL,
			so_long->height * PIXEL, "so_long", true);
	if (!so_long->init)
		ft_error("Error: Failed to initialize MLX");
	load_textures(so_long);
	create_images(so_long);
	put_textures(so_long);
	mlx_key_hook(so_long->init, &ft_keymoves, so_long);
	mlx_loop(so_long->init);
}

void	load_textures(t_so_long *so_long)
{
	so_long->txt_coin = mlx_load_png("./images/coin.png");
	if (!so_long->txt_coin)
		ft_error("Error loading texture: coin");
	so_long->txt_exit = mlx_load_png("./images/exit.png");
	if (!so_long->txt_exit)
		ft_error("Error loading texture: exit");
	so_long->txt_floor = mlx_load_png("./images/floor.png");
	if (!so_long->txt_floor)
		ft_error("Error loading texture: floor");
	so_long->txt_player = mlx_load_png("./images/player.png");
	if (!so_long->txt_player)
		ft_error("Error loading texture: player");
	so_long->txt_wall = mlx_load_png("./images/wall.png");
	if (!so_long->txt_wall)
		ft_error("Error loading texture: wall");
}

void	create_images(t_so_long *so_long)
{
	so_long->img_floor = mlx_texture_to_image(so_long->init, so_long->txt_floor);
	if (!so_long->img_floor)
		ft_error("Error creating image: floor");
	so_long->img_player = mlx_texture_to_image(so_long->init, so_long->txt_player);
	if (!so_long->img_player)
		ft_error("Error creating image: player");
	so_long->img_wall = mlx_texture_to_image(so_long->init, so_long->txt_wall);
	if (!so_long->img_wall)
		ft_error("Error creating image: wall");
	so_long->img_coin = mlx_texture_to_image(so_long->init, so_long->txt_coin);
	if (!so_long->img_coin)
		ft_error("Error creating image: coin");
	so_long->img_exit = mlx_texture_to_image(so_long->init, so_long->txt_exit);
	if (!so_long->img_exit)
		ft_error("Error creating image: exit");
}

void	put_textures(t_so_long *so_long)
{
	int	y;
	int	x;

	y = 0;
	put_floor(so_long);
	while (so_long->height > y)
	{
		x = 0;
		while (so_long->map[y][x] != '\n' && so_long->map[y][x] != '\0')
		{
			if (so_long->map[y][x] == '1')
				mlx_image_to_window(so_long->init, so_long->img_wall,
					x * PIXEL, y * PIXEL);
			else if (so_long->map[y][x] == 'C')
				mlx_image_to_window(so_long->init, so_long->img_coin,
					x * PIXEL, y * PIXEL);
			else if (so_long->map[y][x] == 'E')
				mlx_image_to_window(so_long->init, so_long->img_exit,
					x * PIXEL, y * PIXEL);
			x++;
		}
		y++;
	}
	mlx_image_to_window(so_long->init, so_long->img_player,
		so_long->x * PIXEL, so_long->y * PIXEL);
}

void	put_floor(t_so_long *so_long)
{
	int	y;
	int	x;

	y = 0;
	while (so_long->height > y)
	{
		x = 0;
		while (so_long->map[y][x] != '\n' && so_long->map[y][x] != '\0')
		{
			if (!so_long->img_floor)
			{
				ft_error("Error: img_floor is NULL");
				return ;
			}
			mlx_image_to_window(so_long->init, so_long->img_floor,
				x * PIXEL, y * PIXEL);
			x++;
		}
		y++;
	}
}