#include "libft.h"

int	ft_putstr_withsize_fd(char *s, int fd, int size)
{
	int ret;

	ret = write(fd, s, size);
	if (ret == -1)
		return (ret);
	return (size);
}
