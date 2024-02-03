/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:43:36 by mabertha          #+#    #+#             */
/*   Updated: 2023/10/14 12:45:06 by mabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	measure_len_nbr(int len, size_t nbr, size_t base)
{
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

int	format_args(va_list args, char *str)
{
	int		i;
	int		nb_written;
	char	*hexa_maj;
	char	*hexa_min;

	i = 1;
	hexa_maj = "0123456789ABCDEF";
	hexa_min = "0123456789abcdef";
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == 'u' && str[0] == '%')
		nb_written = get_idux_args(va_arg(args, unsigned int), "0123456789");
	else if (str[i] == 'x' && str[0] == '%')
		nb_written = get_idux_args(va_arg(args, unsigned int), hexa_min);
	else if (str[i] == 'X' && str[0] == '%')
		nb_written = get_idux_args(va_arg(args, unsigned int), hexa_maj);
	else if (str[i] == 'i' && str[0] == '%')
		nb_written = get_idux_args(va_arg(args, int), "0123456789");
	else if (str[i] == 'd' && str[0] == '%')
		nb_written = get_idux_args(va_arg(args, int), "0123456789");
	else if (str[i] == 'p' && str[0] == '%')
		nb_written = get_p_arg(va_arg(args, void *), hexa_min);
	else if ((str[i] == 'c' || str[i] == 's' || str[i] == '%') && str[0] == '%')
		nb_written = get_scpercent_args(str, args);
	return (nb_written);
}

int	search_format_specifier(char *str, int i_str, int i_format, char *format)
{
	while (*(str + i_str) != '%' && *(str + i_str) != '\0')
		i_str++;
	if (i_str == 0 && *str == '%')
	{
		i_str = 1;
		while (*(str + i_str) && *(str + i_str) == ' ')
			i_str++;
		i_format = 0;
		while (format[i_format] && *(str + i_str) != format[i_format])
			i_format++;
		if (format[i_format] == '\0')
			return (-1);
		return (i_str + 1);
	}
	return (i_str);
}

int	read_and_print(char *str, va_list args)
{
	int	index;
	int	checker;
	int	nb_written;

	nb_written = 0;
	while (*str)
	{
		index = search_format_specifier(str, 0, 0, "cspdiuxX%");
		if (index == -1)
			return (nb_written);
		if (*str == '%')
			checker = format_args(args, str);
		else
			checker = ft_putstr_withsize_fd(str, 1, index);
		if (checker == -1)
			return (-1);
		nb_written += checker;
		str += index;
	}
	return (nb_written);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		nb_written;

	if (!str)
		return (-1);
	if (!(*str) || (*str == '%' && str[1] == '\0'))
		return (0);
	va_start(args, str);
	nb_written = read_and_print((char *)str, args);
	va_end(args);
	return (nb_written);
}
