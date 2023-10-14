/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:47:42 by mabertha          #+#    #+#             */
/*   Updated: 2023/10/14 12:47:43 by mabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_link;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	new_list = ft_lstnew((*f)(tmp->content));
	if (new_list == NULL)
		return (NULL);
	tmp = tmp->next;
	while (tmp)
	{
		new_link = ft_lstnew((*f)(tmp->content));
		if (new_link == NULL)
		{
			ft_lstclear(&new_list, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_link);
		tmp = tmp->next;
	}
	return (new_list);
}
