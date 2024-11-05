/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:38:50 by pablogon          #+#    #+#             */
/*   Updated: 2024/10/29 10:06:52 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (*(src[i]))
		i++;
	if (n == 0)
		return (i);
	while (--n && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (i);
}
