/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:45:30 by mabertha          #+#    #+#             */
/*   Updated: 2023/10/14 12:45:32 by mabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int	ft_printf(const char *str, ...);
int	read_and_print(char *str, va_list args);
int	search_format_specifier(char *str, int i_str, int i_format, char *format);
int	format_args(va_list args, char *str);
int	measure_len_nbr(int len, size_t nbr, size_t base);
int	get_p_arg(void *ptr_arg, char *base);
int	get_idux_args(long arg_nbr, char *base);
int	get_scpercent_args(char *str, va_list args);
int	get_cpercent_arg(char format, va_list args);
int	get_s_arg(char *s_arg);

#endif
