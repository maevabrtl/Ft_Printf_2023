#include "ft_printf.h"

int	get_s_arg(char *s_arg)
{
	if (s_arg == NULL)
		return (ft_putstr_withsize_fd("(null)", 1, 6));
	if (*s_arg == '\0')
		return (0);
	return (ft_putstr_withsize_fd(s_arg, 1, ft_strlen(s_arg)));
}

int	get_cpercent_arg(char format, va_list args)
{
	char	c_arg;

	if (format == '%')
		c_arg = '%';
	else
		c_arg = va_arg(args, int);
	return(write(1, &c_arg, 1));
}

int	get_scpercent_args(char *str, va_list args)
{
	int	i;

	i = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == 's')
		return (get_s_arg(va_arg(args, char *)));
	if (str[i] == 'c' || str[i] == '%')
		return(get_cpercent_arg(str[i], args));
	return (ft_putstr_withsize_fd(&(str[1]), 1, 2));
}

int	get_iduxX_args(long arg_nbr, char *base)
{
	int	nb_written;
	int	check;

	nb_written = 0;
	if (arg_nbr == 0)
		nb_written++;
	if (arg_nbr < 0)
	{
		check = write(1, "-", 1);
		if (check == -1)
			return (check);
		nb_written++;
		arg_nbr *= -1;
	}
	nb_written = measure_len_nbr(nb_written, arg_nbr, ft_strlen(base));
	check = ft_putnbrbase(arg_nbr, base);
	if (check == -1)
		return (check);
	return(nb_written);
}

int	get_p_arg(void *ptr_arg, char *base)
{
	int		check;
	size_t	nb_ptr;
	int		nb_written;

	if (ptr_arg == NULL)
	{
		nb_written = ft_putstr_withsize_fd("0x0", 1, 3);
		return (nb_written);
	}
	nb_ptr = (size_t)ptr_arg;
	check = write(1, "0x", 2);
	if (check == -1)
		return (check);
	nb_written = measure_len_nbr(0, nb_ptr, ft_strlen(base));
	if (nb_ptr == 0)
		nb_written = 1;
	else
		nb_written += 2;
	check = ft_putnbrbase(nb_ptr, base);
	if (check == -1)
		return (check);
	return(nb_written);
}
