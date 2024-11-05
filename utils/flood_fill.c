/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:22:19 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/11/05 11:35:12 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	flood_fill(t_solong *so_long, int x, int y)
{
	printf("%i\n %d\n lif1", x, y);
	if (x < 0 || x >= so_long->width || y < 0 || y >= so_long->height) 
		return;
	if (so_long->dup[y][x] == '1' || so_long->dup[y][x] == 'F')
		return;
	so_long->dup[y][x] = 'F';
	flood_fill(so_long, x + 1, y);
	flood_fill(so_long, x - 1, y);
	flood_fill(so_long, x, y + 1);
	flood_fill(so_long, x, y - 1);
}
