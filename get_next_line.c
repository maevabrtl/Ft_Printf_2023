#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize <= 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

int	ft_strchr_index(const char *s, int tofind)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != (char)tofind && s[i])
		i++;
	if (s[i] == (char)tofind)
		return (i);
	return (-1);
}

char	*realloc_copy(char *buf, int index_newline, char *line)
{
	int		len_line;
	int		len_new;
	int		new_index_nl;
	char	*new;
	char	*tocopy;

	if (index_newline == -1)
		new_index_nl = BUFFER_SIZE + 1;
	else
		new_index_nl = index_newline + 2;
	if (!line)
	{
		new = malloc(sizeof(char) * new_index_nl); // faire un calloc pour bzero en meme temps ?
		if (new == NULL)
			return (NULL);
		ft_strlcpy(new, buf, new_index_nl);
		return (new);
	}
	len_line = ft_strlen(line);
	len_new = len_line + new_index_nl;
	new = malloc(sizeof(char) * len_new);
	ft_bzero(new, len_new);
	ft_strlcpy(new, line, len_line + 1);
	ft_strlcpy(&new[len_line], buf, new_index_nl);
	free(line);
	line = NULL;
	return(new);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			nb_read;
	int			index_newline;
	char		buftmp[BUFFER_SIZE + 1];

	if (fd == -1)
		return (NULL);
	line = NULL;
	index_newline = -1;
	nb_read = BUFFER_SIZE;
	while (index_newline == -1)
	{
		index_newline = ft_strchr_index(buf, '\n');
		line = realloc_copy(buf, index_newline, line);
		if (line == NULL)
			return (NULL);
		if (index_newline != -1)
		{
			ft_strlcpy(buftmp, buf, BUFFER_SIZE + 1);
			ft_strlcpy(buf, &buftmp[index_newline + 1], BUFFER_SIZE + 1);
		}
		if (index_newline == -1 && nb_read == BUFFER_SIZE)
		{
			nb_read = read(fd, buf, BUFFER_SIZE);
			if (nb_read == -1)
				return (NULL);
		}
		if (nb_read == 0)
			return (NULL);
	}
	return (line);
}
