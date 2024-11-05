/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:15:22 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/10/23 11:08:13 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	ft_moves(mlx_key_data_t keydata, void *param)
{
	t_solong	*so_long;
	int			new_x;
	int			new_y;
	
	so_long = (t_solong *)param;
	new_x = so_long->x;
	new_y = so_long->y;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(so_long->init);

	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		new_y -= 1;
		else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		new_y += 1;
		else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		new_x -= 1;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		new_x += 1;

	if (passable_box(so_long, new_x, new_y))
	ft_player(so_long);
}

void	ft_moves_w(void *param, mlx_key_data_t keydata)
{
	t_solong	*so_long;
	int 		new_x;
	int			new_y;

	so_long = (t_solong *)param;
	new_x = so_long->x;
	new_y = so_long->y;
	if(keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS
		&& passable_box(so_long, new_x, new_y -1))
	{
		so_long->img_player->instances[0].y -=64;
		so_long->count++;
		printf("moves, count:%d\n", so_long->count);
	}	
}

void ft_moves_a(void *param, mlx_key_data_t keydata)
{
	t_solong	*so_long;
	int			new_x;
	int			new_y;

	so_long = (t_solong *)param;
	new_x = so_long->x;
	new_y = so_long->y;
	if(keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS
		&& passable_box(so_long, new_x, new_y -1))
	{
		so_long->img_player->instances[0].y -=64;
		so_long->count++;
		printf("moves, count:%d\n", so_long->count);
	}	
}

void ft_moves_s(void *param, mlx_key_data_t keydata)
{
	t_solong	*so_long;
	int			new_x;
	int			new_y;

	so_long = (t_solong *)param;
	new_x = so_long->x;
	new_y = so_long->y;
	if(keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS
		&& passable_box(so_long, new_x, new_y + 1))
	{
		so_long->img_player->instances[0].y +=64;
		so_long->count++;
		printf("moves, count:%d\n", so_long->count);
	}	
}

void ft_moves_d(void *param, mlx_key_data_t keydata)
{
	t_solong	*so_long;
	int			new_x;
	int			new_y;

	so_long = (t_solong *)param;
	new_x = so_long->x;
	new_y = so_long->y;
	if(keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS
		&& passable_box(so_long, new_x + 1, new_y))
	{
		so_long->img_player->instances[0].x +=64;
		so_long->count++;
		printf("moves, count:%d\n", so_long->count);
	}	
}
