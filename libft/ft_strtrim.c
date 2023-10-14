#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	if (!set || !s1)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	if (j == 0)
		return(ft_calloc(sizeof(char), 1));
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j]))
		j--;
	newstr = ft_calloc(sizeof(char), j - i + 2);
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, &s1[i], j - i + 2);
	return (newstr);
}
