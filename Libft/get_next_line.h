/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:22:38 by @fgonzal2         #+#    #+#             */
/*   Updated: 2024/10/28 15:24:56 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char			*ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
char			*static_maker(char *static_str, int fd);
char			*make_line(char *static_str, int i);
char			*new_static_maker(char *static_str);
char			*get_next_line(int fd);
size_t			ft_strlen(const char *str);
#endif