#include <libft.h>

int	ft_strlen(char *str)
{
	int		the_num;

	the_num = 0;
	while (*str != '\0')
	{
		the_num++;
		str++;
	}
	return (the_num);
}

char *strrchr(const char *str, int ch)
{
    int i;
    int len = ft_strlen(str);

    for (i = len - 1; i >= 0; i--)
    {
        if (str[i] == ch)
            break;
    }
    if (i>=0)
        return str+i;
    return NULL;
}