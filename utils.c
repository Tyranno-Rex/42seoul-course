#include "philo.h"

long	get_time_in_ms(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
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

int	ft_print_error(char *error, int retur)
{
	if (error == NULL)
		return (retur);
	printf("PHILO : %s\n", error);
	return (retur);
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
