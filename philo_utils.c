#include "philo.h"

// int	ft_atoi(const char *str)
// {
// 	int			i;
// 	long		res;
// 	int			signe;
// 	int			tmp;

// 	i = 0;
// 	res = 0;
// 	signe = 1;
// 	tmp = i;
// 	while (str[i] >= '0' && str[i] <= '9')
// 		res = res * 10 + str[i++] - 48;
// 	if ((res > 9223372036854775807 || (i - tmp) > 20) && signe == -1)
// 		return (0);
// 	else if ((res > 9223372036854775807 || (i - tmp) > 20) && signe == 1)
// 		return (-1);
// 	else
// 		return (res * signe);
// }

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

void	ft_free(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->philo_number)
	{
		pthread_mutex_destroy(&env->forks[i]);
		pthread_mutex_destroy(&env->mutex_nb_eat[i]);
		pthread_mutex_destroy(&env->mutex_eat_time[i]);
		i++;
	}
	pthread_mutex_destroy(&env->m_alive);
	free(env->mutex_eat_time);
	if (env->forks)
		free(env->forks);
	if (env->mutex_nb_eat)
		free(env->mutex_nb_eat);
	if (env->ph)
		free(env->ph);
}

long	get_time_in_ms(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(long time, t_env *env)
{
	struct timeval	start;
	long			start_in_ms;
	long			final_time;

	if (gettimeofday(&start, NULL))
		return (1);
	start_in_ms = get_time_in_ms(start);
	final_time = start_in_ms + time;
	while (check_alive(env) == 0 && start_in_ms < final_time)
	{
		if (gettimeofday(&start, NULL))
			return (1);
		start_in_ms = get_time_in_ms(start);
		usleep(50);
	}
	return (0);
}
