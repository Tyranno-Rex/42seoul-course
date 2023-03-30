#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_print_error(char *error, int retur)
{
	if (error == NULL)
		return (retur);
	printf("PHILO : %s\n", error);
	return (retur);
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

int	print_result(long elapsed_time, int philo, char *msg)
{
	char	time[11];
	char	id[11];
	char	str[40];

	ft_itoa(elapsed_time, time);
	ft_itoa((long)philo, id);
	ft_strcat(time, id, msg, str);
	printf("%s", str);
	return (0);
}
