/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:09:02 by pablogon          #+#    #+#             */
/*   Updated: 2024/10/28 15:25:29 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)str1 != *(unsigned char *)str2)
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
		str1 = (unsigned char *)str1 + 1;
		str2 = (unsigned char *)str2 + 1;
	}
	return (0);
}
