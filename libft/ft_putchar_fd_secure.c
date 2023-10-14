/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_secure.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:48:39 by mabertha          #+#    #+#             */
/*   Updated: 2023/10/14 12:48:40 by mabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd_secure(char c, int fd)
{
	int	ret;

	ret = write(fd, &c, 1);
	if (ret == -1)
		return (ret);
	return (0);
}
