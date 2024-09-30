/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:22:19 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/09/25 16:50:48 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_solong *node, int color, int replacement)
{
	while ( node != NULL)
	{
		if (node->color == color)
		{
			node->color = replacement
			flood_fill(node->left, color + 1, replacement)
			flood_fill(node->right, color - 1, replacement)
			flood_fill(node->up, color, replacement + 1)
			flood_fill(node->down, color, replacement - 1)
		}
		node = node->next;
	}
}