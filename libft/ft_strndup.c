#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	len;
	char	*copy;

	len = 0;
	while (len < n && str[len])
		len++;
	copy = malloc(sizeof(char) * len + 1);
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, str, len);
	copy[len] = '\0';
	return (copy);
}
