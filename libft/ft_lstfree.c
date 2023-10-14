/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:47:18 by mabertha          #+#    #+#             */
/*   Updated: 2023/10/14 12:47:19 by mabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **lst)
{
	t_list	*tmp;
	t_list	*current;

	current = *lst;
	while (current != NULL)
	{
		tmp = (current->next);
		free(current->content);
		free(current);
		current = tmp;
	}
	*lst = NULL;
}
