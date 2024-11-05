/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:13:47 by pablogon          #+#    #+#             */
/*   Updated: 2024/10/28 15:26:04 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < n)
	{
		j = 0;
		k = i;
		while (haystack[k] == needle[j] && k < n)
		{
			k++;
			j++;
			if (needle[j] == '\0')
				return ((char *) & haystack[i]);
		}
		i++;
	}
	return (0);
}
