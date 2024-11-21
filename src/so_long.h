/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:22:33 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/11/18 10:52:02 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../Libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define PIXEL 64

typedef struct s_solong
{
	int					window_height;
	int					window_width;
	int					width;
	int					height;
	int					dup_height;
	int					player;
	int					coin;
	int					total_coins;
	int					exit;
	int					x;
	int					y;
	int					new_x;
	int					new_y;
	int					count;
	char				**map;
	char				**dup;
	void				*win;
	mlx_t				*init;
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
	mlx_image_t			*img_map;
}			t_solong;

void	duplicated_map(t_solong *so_long);
void	player_position(t_solong *so_long);
int		access_check(t_solong *so_long);
void	win(t_solong *so_long);
void	flood_fill(t_solong *so_long, int x, int y);
void	ft_error(const char *msg);
void	ft_mlx_init(t_solong *so_long);
void	load_textures(t_solong *so_long);
void	put_textures(t_solong *so_long);
void	create_images(t_solong *so_long);
void	put_floor(t_solong *so_long);
void	load_map(t_solong *so_long, char *filename);
void	elements_map(t_solong *so_long, char *line);
void	init_so_long(t_solong *so_long);
void	free_map(t_solong *so_long);
void	clean_(t_solong *so_long);
void	ft_moves(mlx_key_data_t keydata, void *param);
void	ft_moves_w(void *param, mlx_key_data_t keydata);
void	ft_moves_a(void *param, mlx_key_data_t keydata);
void	ft_moves_s(void *param, mlx_key_data_t keydata);
void	ft_moves_d(void *param, mlx_key_data_t keydata);
void	ft_player(t_solong *so_long);
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void	ft_randomize(void *param);
void	ft_hook(void *param);
int		passable_box(t_solong *so_long, int new_x, int new_y);
int		ft_strlen_sl(char *str);
int		ft_check_walls(t_solong *so_long);
int		ft_check_correct_characters(t_solong *so_long);
int		ft_check_items_so_long(t_solong *so_long);
int		ft_check_file(char *str);
int		ft_check_map_size(t_solong *so_long, const char *filename);
void	ft_check_so_long(t_solong *so_long, char *file);
void	map_elements(t_solong *so_long);
#endif