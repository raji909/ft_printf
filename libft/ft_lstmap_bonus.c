/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:17:56 by adraji            #+#    #+#             */
/*   Updated: 2025/10/19 21:17:57 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*list;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	list = ft_lstnew(f(lst->content));
	if (!list)
		return (NULL);
	tmp = list;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew(f(lst->content));
		if (!tmp->next)
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (list);
}
