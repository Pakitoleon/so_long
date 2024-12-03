/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:28:11 by pablogon          #+#    #+#             */
/*   Updated: 2024/11/21 15:52:16 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	passable_box(t_so_long *game, int new_x, int new_y)
{
	if (game && game->map && game->map[new_y][new_x] != '1')
	{
		game->x = new_x;
		game->y = new_y;
		return (1);
	}
	return (0);
}
