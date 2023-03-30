#include "philo.h"

int	take_a_fork(t_env *env, int n, int fork)
{
	struct timeval	time;

	if (n != fork)
		usleep(50);
	if (fork == env->philo_number)
		fork = 0;
	if (check_alive(env) == 0)
	{
		if (pthread_mutex_lock(&env->forks[fork]) != 0)
			return (ft_print_error("MUTEX LOCK FORK FAILED", -1));
		if (gettimeofday(&time, NULL) != 0)
			return (ft_print_error("GET TIME OF DAY FAILED", -1));
		if (check_alive(env) == 0)
			print_result(-get_time_in_ms(env->start)
				+ get_time_in_ms(time), n, " has taken a fork\n");
	}	
	return (0);
}
// int	ft_init_mutex_meal_time(t_env *env)
// {
// 	int	i;

// 	i = 0;
// 	env->mutex_eat_time = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * env->philo_number);
// 	if (env->mutex_eat_time == NULL)
// 		return (ft_print_error("ALLOCATION OF MEAL TIME FAILED", -1));
// 	while (i < env->philo_number)
// 	{
// 		if (pthread_mutex_init(&env->mutex_eat_time[i], NULL) != 0)
// 			return (ft_print_error("INIT MUTEX OF MEAL TIME FAILED", -1));
// 		i++;
// 	}
// 	return (0);
// }

int	ft_init_forks(t_env *env)
{
	int	i;

	i = 0;
	env->mutex_nb_eat = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * env->philo_number);
	env->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * env->philo_number);
	env->mutex_eat_time = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) *env->philo_number);
	if (env->forks == NULL || env->mutex_nb_eat == NULL || env->mutex_eat_time == NULL)
		return (ft_print_error("ALLOCATION OF MUTEX FAILED", -1));
	while (i < env->philo_number)
	{
		if (pthread_mutex_init(&env->forks[i], NULL) != 0)
			return (ft_print_error("INIT MUTEX FAILED", -1));
		if (pthread_mutex_init(&env->mutex_nb_eat[i], NULL) != 0)
			return (ft_print_error("INIT MUTEX FAILED", -1));
		if (pthread_mutex_init(&env->mutex_eat_time[i], NULL) != 0)
			return (ft_print_error("INIT MUTEX FAILED", -1));
		i++;
	}
	if (pthread_mutex_init(&env->m_alive, NULL) != 0)
		return (ft_print_error("INIT MUTEX OF ALIVE FAILED", -1));
	return (0);
}
