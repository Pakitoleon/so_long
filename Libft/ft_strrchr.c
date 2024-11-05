/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:53:24 by pablogon          #+#    #+#             */
/*   Updated: 2024/10/28 15:26:05 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char const	*aux;

	aux = 0;
	while (*str)
	{
		if (*str == (char)c)
			aux = str;
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	else
		return ((char *)aux);
}
