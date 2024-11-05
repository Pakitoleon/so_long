/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:09:09 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/11/05 11:34:19 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	ft_player(t_solong *so_long)
{
	char	position;

	if (so_long->x < 0 || so_long->x >= so_long->width || so_long->y < 0 || so_long->y >= so_long->height)
		return;
	position = so_long->map[so_long->y][so_long->x];
	if (position == 'C')
	{
		so_long->coin++;
		so_long->map[so_long->y][so_long->x] = '0';
		mlx_image_to_window(so_long->init, so_long->img_floor,
			so_long->x * 32, so_long->y * 32);
		mlx_delete_image(so_long->init, so_long->img_player);
		so_long->img_player = mlx_texture_to_image(so_long->init, so_long->txt_player);
		mlx_image_to_window(so_long->init, so_long->img_player,
			so_long->x * 32, so_long->y * 32);
	}
	if (position == 'E')
	{
		if (so_long->coin == so_long->total_coins)
			win(so_long);
		else
			so_long->map[so_long->y][so_long->x] = 'E';
	}
	else
		so_long->map[so_long->y][so_long->x] = 'P';
}

/*int	ft_strlen_so_long(char *str)
{
	int	y;

	y = 0;
	if (!str)
		return (0);
	while (str[y] && str[y] != '\n')
		y++;
	return (y);
}*/

void	map_elements(t_solong *so_long)
{
	if (so_long->player != 1)
		ft_error("Error: The map must contain exactly one player.");
	if (so_long->coin < 1)
		ft_error("Error: The map must contain at least one coin.");
	if (so_long->exit < 1)
		ft_error("Error: The map must contain at least one exit.");
}