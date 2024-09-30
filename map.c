/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:09:53 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/09/25 17:38:25 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	ft_load_map(t_so_long *game, char *filename)
{
	int		fd;
	char	*line;
	int		i;
}

void count_map(t_solong *so_long, char *lline)
{
	int		y;
}

void init_map(t_solong *so_long)
{
	so_long->width = 0;
	so_long->height = 0;
	so_long->map = NULL;
	so_long->player = 0;
	so_long->coin = 0;
	so_long->total_coin = 0;
	so_long->exit = 0;
	so_long->count = 0;
	so_long->x = -1;
	so_long->y =-1;
	so_long->init = NULL;
	so_long->img_floor = NULL;
	so_long->img_wall = NULL;
	so_long->img_exit = NULL;
	so_long->img_coin = NULL;
	so_long->img_player = NULL;
	so_long->img_exit = NULL;
	
}

void free_map(t_solong *so_long)
{
	int i;
}

void clean_(t_solong *so_long)
{
	
}