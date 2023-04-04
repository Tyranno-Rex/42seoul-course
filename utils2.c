#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

int	ft_itoa(long num, char *retur)
{
	int		count;
	long	tmp;
	int		i;

	i = 0;
	count = 0;
	tmp = num;
	if (num < 0)
		return (ft_print_error("TIME ERROR", -1));
	if (num == 0)
	{
		retur[0] = '0';
		retur[1] = '\0';
		return (0);
	}
	while (tmp > 0 && ++count >= 0)
		tmp = tmp / 10;
	while (i < count)
	{
		retur[count - 1 - i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	retur[count] = '\0';
	return (0);
}

int	ft_strcat(char *time, char *philo, char *msg, char *retur)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (time[i])
		retur[i++] = time[j++];
	retur[i++] = 'm';
	retur[i++] = 's';
	retur[i++] = ' ';
	retur[i++] = 'p';
	retur[i++] = 'h';
	retur[i++] = 'i';
	retur[i++] = 'l';
	retur[i++] = 'o';
	retur[i++] = ' ';
	j = 0;
	while (philo[j])
		retur[i++] = philo[j++];
	j = 0;
	while (msg[j])
		retur[i++] = msg[j++];
	retur[i] = '\0';
	return (0);
}


