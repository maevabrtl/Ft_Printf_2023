#include "ft_printf.h"

int	get_string_char(va_list args, char *str)
{
	char	*tmp;
	char	c;
	int		i;
	int 	ret;

	i = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == 's')
	{
		tmp = va_arg(args, char *);
		if (tmp == NULL)
			return (ft_putstr_withsize_fd("(null)", 1, 6));
		if (*tmp == '\0')
			return (0);
		return (ft_putstr_withsize_fd(tmp, 1, ft_strlen(tmp)));
	}
	else if (str[i] == 'c' || str[i] == '%')
	{
		if (str[i] == '%')
			c = '%';
		else
			c = va_arg(args, int);
		ret = write(1, &c, 1);
	}
	else
	{
		tmp = &(str[1]);
		return (ft_putstr_withsize_fd(tmp, 1, 2));
	}
	return (ret);
}

int	measure_len_nbr(int len, size_t nbr, size_t base)
{
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

int	get_uxX_args(size_t arg_nbr, char *base)
{
	int	ret;
	int check;

	ret = 0;
	if (arg_nbr == 0)
		ret++;
	ret = measure_len_nbr(ret, arg_nbr, ft_strlen(base));
	check = ft_putnbrunsignedbase(arg_nbr, base);
	if (check == -1)
		return (check);
	return(ret);
}

int	get_p_arg(void *ptr)
{
	int	check;

	check = write(1, "0x", 2);
	if (check == -1)
		return (check);
	return(get_uxX_args((size_t)ptr, "0123456789abcdef") + 2);
}

// while (nbr_copy > 0)
// 	{
// 		nbr_copy /= ft_strlen(base);
// 		ret++;
// 	}

int	get_id_args(long arg_nbr, char *base)
{
	int	ret;
	int check;

	ret = 0;
	if (arg_nbr == 0)
		ret++;
	if (arg_nbr < 0)
	{
		check = write(1, "-", 1);
		if (check == -1)
			return (check);
		ret++;
		arg_nbr *= -1;
	}
	ret = measure_len_nbr(ret, arg_nbr, ft_strlen(base));
	check = ft_putnbrbase(arg_nbr, base);
	if (check == -1)
		return (check);
	return(ret);
}

int	format_args(va_list args, char *formater)
{
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	while (formater[i] && formater[i] == ' ')
		i++;
	if (formater[i] == 'u' && formater[0] == '%')
		ret = get_uxX_args(va_arg(args, unsigned int), "0123456789");
	else if (formater[i] == 'x' && formater[0] == '%')
		ret = get_uxX_args(va_arg(args, unsigned int), "0123456789abcdef");
	else if (formater[i] == 'X' && formater[0] == '%')
		ret = get_uxX_args(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (formater[i] == 'i' && formater[0] == '%')
		ret = get_id_args(va_arg(args, int), "0123456789");
	else if (formater[i] == 'd' && formater[0] == '%')
		ret = get_id_args(va_arg(args, int), "0123456789");
	else if (formater[i] == 'p' && formater[0] == '%')
		ret = get_p_arg(va_arg(args, void *));
	else if ((formater[i] == 'c' || formater[i] == 's' || formater[i] == '%') && formater[0] == '%')
		ret = get_string_char(args, formater);
	return (ret);
}

int	search_format_specifier(char *str)
{
	char	*format;
	int		i;
	int		n;

	n = 1;
	format = "cspdiuxX%";
	while (*(str + n) && *(str + n) == ' ')
		n++;
	i = 0;
	while (format[i] && *(str + n) != format[i])
		i++;
	if (format[i] == '\0')
	{
		ft_putstr_fd("Error : invalid conversion specifier \'", 2);
		write(2, &str[n], 1);
		ft_putstr_fd("\'. Supported ones are \"cspdiuxX%\".", 2);
		ft_putstr_fd(" Behavior will be undefined.\n", 2);
		return (-1);
	}
	return (n + 1);
}

int	fill_list(char *str, va_list args)
{
	int	n;
	int	checker;
	int	ret;

	ret = 0;
	if(*str == '%' && str[1] == '\0')
		return (0);
	while (*str)
	{
		n = 0;
		while (*(str + n) != '%' && *(str + n) != '\0')
			n++;
		if (n == 0 && *str == '%')
			n = search_format_specifier(str);
		if (n == -1)
		{
			str++;
			n = 1;
		}
		if (*str == '%')
			checker = format_args(args, str);
		else
			checker = ft_putstr_withsize_fd(str, 1, n);
		if (checker == -1)
			return (-1);
		ret += checker;
		str += n;
	}
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		ret;

	if (!str)
		return (-1);
	if (!(*str))
		return (0);
	va_start(args, str);
	ret = fill_list((char *)str, args);
	va_end(args);
	return (ret);
}
