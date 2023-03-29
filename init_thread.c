#include "philo.h"

int	check_alive(t_env *env)
{
	int	flag;

	if (pthread_mutex_lock(&env->m_alive))
		return (-1);
	flag = env->life_flag;
	if (pthread_mutex_unlock(&env->m_alive))
		return (-1);
	return (flag);
}

int	ft_init_meal_time(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->philo_number)
	{
		if (pthread_mutex_lock(&env->mutex_eat_time[i]))
			return (print_error("MUTEX LOCK ERROR (meal_time)", -1));
		env->ph[i].meal_time.tv_sec = env->start.tv_sec;
		env->ph[i].meal_time.tv_usec = env->start.tv_usec;
		if (pthread_mutex_unlock(&env->mutex_eat_time[i]))
			return (print_error("MUTEX UNLOCK ERROR (meal_time)", -1));
		i++;
	}
	return (0);
}

int	ft_init_thread(t_env *env)
{
	int	i;

	i = -1;
	env->ph = (t_philo *)malloc((env->philo_number) * sizeof(t_philo));
	if (env->ph == NULL || ft_init_meal_time(env))
		return (1);
	while (++i < env->philo_number)
	{
		env->ph[i].id = i;
		env->ph[i].num_of_eat = env->num_of_eat;
		env->ph[i].env = env;
		if (pthread_create(&env->ph[i].thread, NULL, launch_thread,
				(void *)&env->ph[i]) != 0)
			return (1);
	}
	if (launch_waiter(env))
		return (1);
	return (0);
}
