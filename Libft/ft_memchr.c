/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:36:25 by pablogon          #+#    #+#             */
/*   Updated: 2024/10/28 15:25:27 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *str, int c, size_t n)
{
	unsigned char	*str_ptr;
	unsigned char	c_ptr;

	str_ptr = (unsigned char *)str;
	c_ptr = (unsigned char)c;
	while (n--)
	{
		if (*str_ptr == c_ptr)
			return (str_ptr);
		str_ptr++;
	}
	return (0);
}
