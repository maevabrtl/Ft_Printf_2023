#include "libft.h"

static int  count_w(char const *str, char sep)
{
  int i;
  int count;

  count = 0;
  i = 0;
  while (str[i])
  {
    while (str[i] && str[i] == sep)
      i++;
    if (str[i])
      count++;
    while (str[i] && str[i] != sep)
      i++;
  }
  return (count);
}

static int  size_w(char const *str, char sep)
{
  int i;

  i = 0;
  while (str[i] && str[i] != sep)
    i++;
  return (i);
}

static char *write_w(char const *str, int len)
{
  char  *word;
  int   i;

  i = 0;
  word = (char *)malloc(sizeof(char) * (len + 1));
  if (!word)
    return (NULL);
  while (i < len)
  {
    word[i] = str[i];
    i++;
  }
  word[i] = '\0';
  return (word);
}

static void ft_free(char **res, int len)
{
  int i;

  i = 0;
  while (i <= len)
    free(res[i++]);
  free(res);
}

char  **ft_split(char const *str, char sep)
{
  char  **res;
  int   i;
  int   count_words;

  i = 0;
  count_words = count_w(str, sep);
  res = (char **)malloc(sizeof(char *) * (count_words + 1));
  if (!res)
    return (NULL);
  while (i < count_words)
  {
    while (*str && *str == sep)
      str++;
    res[i] = write_w(str, size_w(str, sep));
    if (!res[i])
    {
      ft_free(res, i);
      return (NULL);
    }
    while (*str && *str != sep)
      str++;
    i++;
  }
  res[i] = NULL;
  return (res);
}
