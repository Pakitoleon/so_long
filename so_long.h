/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:22:33 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/09/26 10:26:32 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define = SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line_bonus.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_solong
{
	mlxp_t				*init;
	mlx_window_t		*win;
	mlx_texture_t		*txt_coin;
	mlx_texture_t		*txt_exit;
	mlx_texture_t		*txt_floor;
	mlx_texture_t		*txt_player;
	mlx_texture_t		*txt_wall;
	mlx_texture_t		*txt_enemy;
	mlx_image_t			*img_coin;
	mlx_image_t			*img_exit;
	mlx_image_t			*img_floor;
	mlx_image_t			*img_player;
	mlx_image_t			*img_wall;
	mlx_image_t			*img_enemy;
	mlx_map_t			*map;
}			t_solong;

#endif