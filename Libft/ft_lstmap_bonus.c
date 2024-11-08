/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:14:17 by pablogon          #+#    #+#             */
/*   Updated: 2024/10/28 15:25:24 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;
	t_list	*newcontent;

	newlst = NULL;
	while (lst != NULL)
	{
		newcontent = f(lst->content);
		if (newcontent == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		newnode = ft_lstnew(newcontent);
		if (newnode == NULL)
		{
			ft_lstclear(&newlst, del);
			free(newcontent);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newnode);
		lst = lst->next;
	}
	return (newlst);
}
