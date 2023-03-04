#include "push_swap.h"

void	check_dup(int argc_len, int *str_int)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < argc_len)
	{
		while (j < argc_len)
		{
			if (str_int[j] == ' ')
				j++;
			else if (str_int[i] == str_int[j])
				show_free_error_2("Error", str_int);
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	check_atoi(char *str, int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
	{
		while (str[i] != '\0')
		{
			if (str[i] != '0' && str[i] != '+' && str[i] != '-')
				return (1);
			i++;
		}
	}
	return (0);
}