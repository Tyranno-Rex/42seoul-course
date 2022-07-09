#include "includes/ft.h"

int func_str_to_int(char *str)
{
	long long	result;
	int	plus;

	result = 0;
	plus = 1;
	while (*str == '\r' || *str == '\v' || *str == '\t' || *str == '\n' \
		|| *str == 32 || *str == '\f')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			plus = plus * -1;
		str++;
	}
	if ((*str >= '0') && (*str <= '9'))
	{
		while ((*str >= '0') && (*str <= '9'))
		{
			result = (result * 10) + ((*str) - '0');
			str++;
		}
	}
	return (result * plus);
}

int main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac != 4)
		return (0);
	if ((char)av[2] == '+')
		i = func_plus(av[1], av[3]);
	else if ((char)av[2] == '-')
		i = func_minus(av[1], av[3]);
	else if ((char)av[2] == '/')
		i = func_divide(av[1], av[3]);
	else if ((char)av[2] == '*')
		i = func_multiply(av[1], av[3]);
	ft_putnbr(i);
	return (0);
}


