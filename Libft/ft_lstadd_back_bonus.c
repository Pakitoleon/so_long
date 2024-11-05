/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:55:39 by pablogon          #+#    #+#             */
/*   Updated: 2024/10/28 15:25:12 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_final;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lst_final = *lst;
	while ((*lst)->next)
		*(lst) = (*lst)->next;
	(*lst)->next = new;
	*lst = lst_final;
}
