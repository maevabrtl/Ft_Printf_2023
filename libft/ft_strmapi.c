#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstr;
	int		i;

	if (!s || !f)
		return (NULL);
	newstr = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		newstr[i] =	(*f)(i, s[i]);
		i++;
	}
	return (newstr);
}
