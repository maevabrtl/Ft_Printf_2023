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
