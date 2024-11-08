/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:04:58 by pablogon          #+#    #+#             */
/*   Updated: 2024/10/28 15:25:58 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_(const char *str1, const char *str2)
{
	char	*ret;
	int		len;

	if (!str1 || !str2)
		return (0);
	len = ft_strlen(str1) + ft_strlen(str2);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, str1, len + 1);
	ft_strlcat(ret, str2, len + 1);
	return (ret);
}
