#include "libft.h"


char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	int		i;
	int		flag;
	int		len_find;

	len_find = 0;
	if (to_find[0] == '\0')
		return (&str[0]);
	while (to_find[len_find] != '\0')
		len_find++;
	flag = -1;
	while (str[++flag] != '\0' && flag < len)
	{
		if (str[flag] == to_find[0])
		{	
			i = 0;
			while (str[flag + i] == to_find[i] && i < len_find)
				i++;
			if (to_find[i] == '\0')
				return (&str[flag]);
		}
	}
	return (0);
}
