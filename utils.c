#include "philosopher.h"

int	ft_atoi(const char *the_char)
{
	int			i;
	int			sign;
	long long	n;

	i = 0;
	sign = 1;
	n = 0;
	while (the_char[i] == ' ' || the_char[i] == '\n' || the_char[i] == '\t' || \
			the_char[i] == '\v' || the_char[i] == '\f' || the_char[i] == '\r')
		i++;
	if (the_char[i] == '-')
		sign *= -1;
	if (the_char[i] == '-' || the_char[i] == '+')
		i++;
	while (the_char[i] && the_char[i] >= '0' && the_char[i] <= '9')
	{
		if (n * sign > 2147483647)
			return (-1);
		else if (n * sign < -2147483648)
			return (0);
		else
			n = n * 10 + (the_char[i] - '0');
		i++;
	}
	return (n * sign);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (c);
	else
		return (0);
}

void ft_showe_error(char *msg)
{
	printf("%s", msg);
	exit(EXIT_FAILURE);
}