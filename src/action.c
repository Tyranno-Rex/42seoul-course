#include "philosopher.h"


ft_usleep()


int	eating(t_philo *ph)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		return (1);
	print_result(get_time_in_ms(time) - get_time_in_ms(ph->env->start), ph->id + 1, " is eating\n");
	if (ft_usleep(ph->env->eat_time, ph->env) != 0)
		return (1);
	if (pthread_mutex_lock(&ph->env->m_nb_of_meal[ph->id]))
		return (1);
	ph->num_of_eat--;
	if (pthread_mutex_unlock(&ph->env->m_nb_of_meal[ph->id]))
		return (1);
	return (0);
}

int	thinking(t_philo *ph)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		return (1);
	print_result(get_time_in_ms(time) -get_time_in_ms(ph->env->start), ph->id + 1, " is thinking\n");
	return (0);
}

int	sleeping(t_philo *ph)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		return (1);
	print_result(get_time_in_ms(time) -get_time_in_ms(ph->env->start) , ph->id + 1, " is sleeping\n");
	if (ft_usleep(ph->env->sleep_time, ph->env) != 0)
		return (1);
	return (0);
}
