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


char *ft_itoa(int n)
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
	return (result);
}

int ft_print_int(char *str)
{
	int i = 0;

	if (!str)
	{
		ft_putstring("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void ft_putint(int n)
{
	int len;
	char *int_to_char;

	len = 0;
	int_to_char = ft_itoa(n);
	// printf("printf test: %s\n", &int_to_char);
	len = ft_print_int(int_to_char);
	free (int_to_char);
}