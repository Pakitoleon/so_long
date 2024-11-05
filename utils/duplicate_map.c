/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:54:18 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/11/05 16:02:28 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void duplicated_map(t_solong *so_long)
{
	int y;

	so_long->dup = (char **)malloc(sizeof(char *) * (so_long->height + 1));
	if (!so_long->dup)
		ft_error("Error: malloc memory for duplicated map");
	y = 0;
	while (y < so_long->height)
	{
		so_long->dup[y] = ft_strdup(so_long->map[y]);
		printf("\n%s\n%s\n", so_long->map[y], so_long->dup[y]);
		if (!so_long->dup[y])
		{
			while (y > 0)
				free(so_long->dup[--y]);
			free(so_long->dup);
			ft_error("Error: couldn't duplicated map line");
		}
		y++;
	}
	so_long->dup[y] = NULL;
}

void player_position(t_solong *so_long)
{
	int x;
	int y;

	y = 0;
	while (y < so_long->height)
	{
		x = 0;
		while (x < so_long->width)
		{
			if (so_long->map[y][x] == 'P')
			{
				so_long->x = x;
				so_long->y = y;
				return;
			}
			x++;
		}
		y++;
	}
	so_long->x = -1;
	so_long->y = -1;
}

int access_check(t_solong *so_long)
{
	int x;
	int y;

	y = 0;
	while (y < so_long->height)
	{
		if (so_long->dup[y] == NULL)
		{
			ft_error("Error: Invalid map data\n");
			return (0);
		}
		x = 0;
		while (x < so_long->width)
		{
			if (so_long->dup[y][x] == '\0')
			{
				ft_error("Error: Invalid map data\n");
				return (0);
			}
			if (so_long->dup[y][x] == 'C' || so_long->dup[y][x] == 'E' || so_long->dup[y][x] == 'P')
			{
				ft_error("Error: duplicated map not C, E o P\n");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void win(t_solong *so_long)
{
	printf("You win the so_long!\n");
	mlx_terminate(so_long->init);
	exit(0);
}
