#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *tmp = malloc(sizeof(char)* (len - start) + 1);
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while(s[i])
	{
		if (i >= start && i <= len -1)
		{
			tmp[j] = s[i];
			j++;
		}
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}