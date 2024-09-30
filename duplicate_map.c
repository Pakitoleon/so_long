/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:54:18 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/09/30 12:55:28 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void duplicated_map(t_solong *so_long)
{
	int y;
	
	y = 0;
	so_long->dub = (char ***)malloc(sizeof(char *) * (so_long->dub_height +1));
	if (!so_long->dub)
		ft_error("Error:no allocated memory for duplicated map\n");
	while (y < so_long->dub_height)
	{
		so_long->dub[y] = ft_strdup(so_long->map[y]);
		if (!so_long->dub[y])
			ft_error ("Error no assign memory for duplicate \n")
		y++;
	}
	so_long->dub[y] = NULL
}

void free_duplicated_map(t_solong *so_long)
{
	int i;
}

void player_position(t_solong *so_long)
{
	int x;
	int y;
}

int access_check(t_solong *so_long)
{
	int x;
	int y;
}

void win(t_solong *so_long)
{
	printf("You win the game!\n");
	mlx_terminate(so_long->init);
	exit(0);
}