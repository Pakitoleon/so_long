/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:09:53 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/11/05 14:50:21 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	load_map(t_solong *so_long, char *filename)
{
	int		fd;
	char	*line;
	int		x;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Error: Couldn't open the map file");
	so_long->map = (char **)malloc(sizeof(char *) * (so_long->height + 1));
	if (!so_long->map)
		ft_error("Error: Couldn't allocate memory to the map.");
    line = get_next_line_bonus(fd);
	x = 0;
	while (line)
	{
		so_long->map[x] = ft_strdup(line);
		if (!so_long->map[x])
			ft_error("Error: Couldn't duplicate line");
		so_long->width = ft_strlen(line);
		elements_map(so_long, line);
		free(line);
		line = get_next_line_bonus(fd);
		x++;
		printf("\nhola\n");
		printf("\n%s", line);
	}
	so_long->map[x] = NULL;
	close(fd);
}

void	elements_map(t_solong *so_long, char *line)
{
	int		y;

	y = 0;
	while(line[y])
	{
		if (line[y] == 'P')
			so_long->player++;
		else if (line[y] == 'C')
			so_long->total_coins++;
		else if (line[y] == 'E')
			so_long->exit++;
		y++;
	}
}

void	init_so_long(t_solong *so_long)
{
	so_long->width = 0;
	so_long->height = 0;
	so_long->map = NULL;
	so_long->player = 0;
	so_long->coin = 0;
	so_long->total_coins = 2;
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
	so_long->dup = NULL;
	
}

void	free_map(t_solong *so_long)
{
	int i;
	
	i = 0;
	
	if (so_long->map)
	{
		i = so_long->height;
		while (i > 0)
		{
			free(so_long->map[--i]);
		}
		so_long->map = NULL;
		free(so_long->map);	
	}
}

void	clean_(t_solong *so_long)
{
	if (so_long->map)
		free_map(so_long);
	mlx_delete_texture(so_long->txt_coin);
	mlx_delete_texture(so_long->txt_exit);
	mlx_delete_texture(so_long->txt_wall);
	mlx_delete_texture(so_long->txt_player);
	mlx_delete_texture(so_long->txt_floor);
	mlx_terminate(so_long->init);
}