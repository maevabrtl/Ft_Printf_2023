#include "libft.h"

int	ft_putchar_fd_secure(char c, int fd)
{
	int	ret;

	ret = write(fd, &c, 1);
	if (ret == -1)
		return (ret);
	return (0);
}
