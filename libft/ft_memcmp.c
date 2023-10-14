/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Maya <Maya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 08:39:13 by mabertha          #+#    #+#             */
/*   Updated: 2023/01/23 21:06:21 by Maya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*s;
	size_t			i;

	str = (unsigned char*)s1;
	s = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (str[i] != s[i])
			return (str[i] - s[i]);
		i++;
	}
	return (0);
}
