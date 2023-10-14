/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:51:19 by mabertha          #+#    #+#             */
/*   Updated: 2023/10/14 12:51:20 by mabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	slen;
	size_t	newlen;
	size_t	i;

	slen = ft_strlen(s);
	if (start >= slen || slen == 0)
		return (ft_calloc(sizeof(char), 1));
	if (len > slen - start)
		newlen = slen - start;
	else
		newlen = len;
	newstr = ft_calloc(sizeof(char), newlen + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (i < newlen && start < slen)
		newstr[i++] = s[start++];
	return (newstr);
}
