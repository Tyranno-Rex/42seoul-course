#include "philo.h"

int	check_time_last_meal(t_env *env, int i, int *ret)
{
	struct timeval	time;

	if (*ret == 2)
		return (2);
	if (gettimeofday(&time, NULL)
		|| pthread_mutex_lock(&env->mutex_eat_time[i]))
		return (1);
	if (get_time_in_ms(time) - get_time_in_ms(env->ph[i].meal_time)
		>= env->when_die)
	{
		if (pthread_mutex_unlock(&env->mutex_eat_time[i])
			|| pthread_mutex_lock(&env->m_alive))
			return (1);
		env->life_flag = 1;
		if (pthread_mutex_unlock(&env->m_alive) || usleep(1000))
			return (1);
		env->check_dead = i + 1;
		if (gettimeofday(&time, NULL))
			return (1);
		print_result(-get_time_in_ms(env->start)
			+ get_time_in_ms(time), env->check_dead, " died\n");
		return (2);
	}
	pthread_mutex_unlock(&env->mutex_eat_time[i]);
	return (0);
}

int	check_nb_of_meal(t_env *env, int *ret)
{
	int	i;

	i = 0;
	while (i < env->philo_number)
	{
		if (pthread_mutex_lock(&env->mutex_nb_eat[i]))
			return (-1);
		if (env->ph[i].num_of_eat > 0)
		{
			if (pthread_mutex_unlock(&env->mutex_nb_eat[i]))
				return (-1);
			return (0);
		}
		if (pthread_mutex_unlock(&env->mutex_nb_eat[i]))
			return (-1);
		i++;
	}
	if (pthread_mutex_lock(&env->m_alive))
		return (1);
	env->life_flag = 1;
	if (pthread_mutex_unlock(&env->m_alive))
		return (1);
	*ret = 2;
	return (2);
}

void	*launch_waiter(t_env *env)
{
	int	i;
	int	ret;

	ret = 0;
	while (check_alive(env) == 0)
	{
		i = 0;
		if (check_nb_of_meal(env, &ret) == -1)
			return ("Error");
		while (i < env->philo_number)
		{			
			ret = check_time_last_meal(env, i, &ret);
			if (ret == 2)
			{
				i = -1;
				while (++i < env->philo_number)
					pthread_detach(env->ph[i].thread);
			}
			else if (ret == 1)
				return ("Error");
			usleep(500);
			i++;
		}
	}
	return (NULL);
}
