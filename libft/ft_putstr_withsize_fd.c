/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_withsize_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:49:19 by mabertha          #+#    #+#             */
/*   Updated: 2023/10/14 12:49:19 by mabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_withsize_fd(char *s, int fd, int size)
{
	int	ret;

	ret = write(fd, s, size);
	if (ret == -1)
		return (ret);
	return (size);
}
