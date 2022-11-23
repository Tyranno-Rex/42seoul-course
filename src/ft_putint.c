#include "../include/ft_printf.h"

char	*func_arr(char *c, unsigned int number, int len)
{
	while (number > 0)
	{
		c[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (c);
}

int	func_len(int n)
{
	int		len;

	len = 0;
	if (n <= 0)
		len += 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}


void ft_itoa(int n)
{
	unsigned int		number;
	long int			len;
	char				*result;
	int					sign;

	sign = 1;
	len = func_len(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!(result))
		return (0);
	result[len--] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		number = n * -1;
		result[0] = '-';
	}
	else
		number = n;
	result = func_arr(result, number, len);
	write(1, result, func_len(result));
}

void	ft_putint(va_list the_char)
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
	ft_itoa(n * sign);
}