#include "ft_printf.h"

int	ft_putstr_withsize_fd(char *s, int fd, int size)
{
	int ret;

	ret = write(fd, s, size);
	if (ret == -1)
		return (ret);
	return (size);
}

char	*get_pointer_adress(va_list args)
{
	char	*tmp;
	char	*ret;

	tmp = ft_utoabase((size_t)va_arg(args, void *), 16, 0);
	ret = malloc(sizeof(char) * ft_strlen(tmp) + 3);
	ft_strlcpy(ret, "0x", 3);
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(&(ret[2]), tmp, ft_strlen(tmp) + 1);
	free(tmp);
	tmp = NULL;
	return (ret);
}

char	*char_to_str(char c)
{
	char *ret;

	ret = malloc(sizeof(char) * 2);
	if (ret == NULL)
		return (NULL);
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}

char	*get_string_char(va_list args, char *str)
{
	char	*tmp;
	char	c;
	int		i;

	if (str[0] != '%')
		return (ft_strndup(str, ft_strlen(str) + 1));
	i = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == 's')
	{
		tmp = va_arg(args, char *);
		if (tmp == NULL)
			return (ft_strndup("(null)", 6));
		return (ft_strndup(tmp, ft_strlen(tmp) + 1));
	}
	if (str[i] == '%')
		c = '%';
	else if (str[i] == 'c')
	{
		c = va_arg(args, int);
		if (c == -65)
			c = -64;
		if (c == 0)
			return (char_to_str(-65));
	}
	else
		return (ft_strndup(&(str[1]), 2));
	return (char_to_str(c));
}

int	format_args(va_list args, char *formater)
{
	char	*arg;
	int		i;
	int		ret;

	arg = NULL;
	i = 1;
	while (formater[i] && formater[i] == ' ')
		i++;
	if (formater[i] == 'u' && formater[0] == '%')
		arg = ft_utoabase(va_arg(args, unsigned int), 10, 0);
	else if (formater[i] == 'x' && formater[0] == '%')
		arg = ft_utoabase(va_arg(args,  unsigned int), 16, 0);
	else if (formater[i] == 'X' && formater[0] == '%')
		arg = ft_utoabase(va_arg(args, unsigned int), 16, 1);
	else if (formater[i] == 'i' && formater[0] == '%')
		arg = ft_itoabase(va_arg(args, int), 10);
	else if (formater[i] == 'd' && formater[0] == '%')
		arg = ft_itoabase( va_arg(args, int), 10);
	else if (formater[i] == 'p' && formater[0] == '%')
		arg = get_pointer_adress(args);
	if (arg == NULL)
		arg = get_string_char(args, formater);
	free(formater);
	formater = NULL;
	ret = ft_strlen(arg);
	if (arg[0] == -65)
	{
		// dprintf(2, "in format args in -65 condition\n");
		arg[0] = 0;
		ret = 1;
	}
	// dprintf(2, "in format args arg = |%s|\n", arg);
	ret = ft_putstr_withsize_fd(arg, 1, ret);
	free(arg);
	arg = NULL;
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
	char *formater;

	ret = 0;
	while (*str)
	{
		if(*str == '%' && str[1] == '\0') // casse si modulo a la fin ???
			return (0);
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
		formater = ft_strndup(str, (size_t)n);
		if (formater == NULL)
			return (-1);
		checker = format_args(args, formater);
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
