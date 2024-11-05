/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:01:04 by pablogon          #+#    #+#             */
/*   Updated: 2024/10/28 15:25:14 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*temp;

	aux = *lst;
	while (aux != NULL)
	{
		temp = aux->next;
		del(aux->content);
		free(aux);
		aux = temp;
	}
	*lst = NULL;
}
