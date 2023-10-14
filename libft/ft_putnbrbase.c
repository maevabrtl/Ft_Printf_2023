/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:48:55 by mabertha          #+#    #+#             */
/*   Updated: 2023/10/14 12:48:56 by mabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbrbase(size_t nbr, char *base)
{
	size_t	base_len;
	int		check;

	check = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
	{
		check = ft_putnbrbase(nbr / base_len, base);
		if (check == -1)
			return (-1);
		check = ft_putnbrbase(nbr % base_len, base);
		if (check == -1)
			return (-1);
	}
	else
	{
		check = ft_putchar_fd_secure(base[nbr], 1);
		if (check == -1)
			return (-1);
	}
	return (0);
}
