#include "philo.h"

int	eating(t_philo *ph)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		return (1);
	print_result(-get_time_in_ms(ph->env->start)
		+ get_time_in_ms(time), ph->id + 1, " is eating\n");
	if (ft_usleep(ph->env->when_eat, ph->env) != 0)
		return (1);
	if (pthread_mutex_lock(&ph->env->mutex_nb_eat[ph->id]))
		return (1);
	ph->num_of_eat--;
	if (pthread_mutex_unlock(&ph->env->mutex_nb_eat[ph->id]))
		return (1);
	return (0);
}

int	sleeping(t_philo *ph)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		return (1);
	print_result(-get_time_in_ms(ph->env->start) + get_time_in_ms(time), ph->id + 1, " is sleeping\n");
	if (ft_usleep(ph->env->when_sleep, ph->env) != 0)
		return (1);
	return (0);
}

int	thinking(t_philo *ph)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		return (1);
	print_result(-get_time_in_ms(ph->env->start)
		+ get_time_in_ms(time), ph->id + 1, " is thinking\n");
	return (0);
}

int	ft_manage_forks(t_philo *ph)
{
	if (ph->id % 2 == 0)
	{
		if (take_a_fork(ph->env, ph->id + 1, ph->id) != 0)
			return (1);
		if (ph->env->philo_number == 1
			|| take_a_fork(ph->env, ph->id + 1, ph->id + 1) != 0)
			return (1);
	}
	else
	{
		if (take_a_fork(ph->env, ph->id + 1, ph->id + 1) != 0)
			return (1);
		if (ph->env->philo_number == 1
			|| take_a_fork(ph->env, ph->id + 1, ph->id) != 0)
			return (1);
	}
	return (0);
}

void	*launch_thread(void *arg)
{
	t_philo			*ph;
	struct timeval	time;	

	ph = (t_philo *)arg;
	while (check_alive(ph->env) == 0)
	{
		if (ft_manage_forks(ph)
			|| pthread_mutex_lock(&ph->env->mutex_eat_time[ph->id])
			|| gettimeofday(&ph->meal_time, NULL)
			|| pthread_mutex_unlock(&ph->env->mutex_eat_time[ph->id]))
			return ("Error");
		if (check_alive(ph->env) == 0 && eating(ph))
			return ("Error");
		if (gettimeofday(&time, NULL)
			|| pthread_mutex_unlock(&ph->env->forks[ph->id])
			|| pthread_mutex_unlock(&ph->env->forks[(ph->id + 1)
					% ph->env->philo_number]))
			return ("Error");
		if (check_alive(ph->env) == 0 && sleeping(ph))
			return ("Error");
		if (check_alive(ph->env) == 0 && thinking(ph))
			return ("Error");
	}
	return (NULL);
}
