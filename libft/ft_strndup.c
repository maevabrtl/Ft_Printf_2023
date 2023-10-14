/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:50:43 by mabertha          #+#    #+#             */
/*   Updated: 2023/10/14 12:50:43 by mabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	len;
	char	*copy;

	len = 0;
	while (len < n && str[len])
		len++;
	copy = malloc(sizeof(char) * len + 1);
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, str, len);
	copy[len] = '\0';
	return (copy);
}
