#include "reader.h"

char	*ft_strchr(const char *s, int c) // MOUAD ft_strchr libft
{
	int		i;
	char	char_c;

	i = 0;
	char_c = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == char_c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (0);
}

size_t	ft_strlen(const char *s) //check MOUAD STRLEN
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
