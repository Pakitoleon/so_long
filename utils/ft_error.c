/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:56:48 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/11/05 12:18:11 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void ft_error (const char *msg)
{
	write (2, msg, ft_strlen(msg));
	write (2, "\n", 1);
	exit (EXIT_FAILURE);
}

int	ft_check_map_size(t_solong *so_long, const char *filename)
{
	int		fd;
	char	*line;
	int		line_length;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_error("Error: Failed to open map file");
		return(0);
	}

	so_long->height = 0;
	line = get_next_line_bonus(fd);
	if (line)
	{
		line_length = ft_strlen(line);
		if (line[line_length - 1] == '\n')
			line_length--;
		so_long->width = line_length;
		free(line);
		so_long->height++;
	}
	while ((line = get_next_line_bonus(fd)) != NULL)
	{
		line_length = ft_strlen(line);
		if (line[line_length - 1] == '\n')
			line_length--;
		if (line_length != so_long->width)		
		{
			free(line);
			close(fd);
			return (0);
		}
		free (line);
		so_long->height++;
	}
	close (fd);
	return (1);
}

int	ft_check_file(char *str)
{
	int	y;

	y = 0;
	if (ft_strlen(str) > 4)
	{
		while (str[y])
		{
			if (ft_strncmp(&str[y], ".ber\0", 5) == 0)
			{
				return (1);
			}
			y++;
		}
	}
	return (0);
}

int	ft_check_items_so_long(t_solong *so_long)
{
	if (so_long->total_coins >= 1 && so_long->player == 1 && so_long->exit == 1)
		return (1);
	ft_error("Error: The map does not contain the specified items");
	return (0);
}

int	ft_check_correct_characters(t_solong *so_long)
{
	int	y;
	int	x;

	y = 0;
	while (y < so_long->height)
	{
		x = 0;
		while (so_long->map[y] && so_long->map[y][x])
		{
			if (so_long->map[y][x] != 'P' && so_long->map[y][x] != 'C'
			&& so_long->map[y][x] != 'E' && so_long->map[y][x] != '1'
			&& so_long->map[y][x] != '0' && so_long->map[y][x] != '\n')
				ft_error ("Error: Characters not allowed");
			x++;
		}
		y++;
	}
	return (ft_check_items_so_long(so_long));
}

int	ft_check_walls(t_solong *so_long)
{
	int	y;
	int	x;

	y = 0;
	while (y < so_long->height)
	{
		if (so_long->map[y][0] != '1' || so_long->map[y][so_long->width - 1] != '1')
		{
			printf("\n%s, %c\n", so_long->map[y], so_long->map[y][so_long->width]);
			ft_error ("Error: The map is not surrounded by walls1");
		}
		y++;
	}
	x = 0;
	while (x < so_long->width)
	{
		if (so_long->map[0][x] != '1' || so_long->map[so_long->height - 1][x] != '1')
		{
			printf("\n%c, \n%c, %c\n",so_long->width, so_long->map[x][0], so_long->map[x][so_long->height]);
			ft_error ("Error: The map is not surrounded by walls2");
		}
		x++;
	}
	return (1);
}
