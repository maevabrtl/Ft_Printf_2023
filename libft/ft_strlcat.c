/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:50:07 by mabertha          #+#    #+#             */
/*   Updated: 2023/10/14 12:50:08 by mabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;
	size_t	j;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	j = dstlen;
	if (dstlen >= dstsize)
		dstlen = dstsize;
	if (srclen == 0 || dstlen == dstsize)
		return (dstlen + srclen);
	while (src[i] && j < dstsize - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (dstlen + srclen);
}
