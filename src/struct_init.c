#include "philosopher.h"

void ft_can_clear(int ac, char **av, t_data *data)
{
	data->philo_num = ft_atoi(av[1]);
	data->philo_span = ft_atoi(av[2]);
	data->philo_eat = ft_atoi(av[3]);
	data->philo_sleep = ft_atoi(av[4]);
	data->philo_clear = ft_atoi(av[5]);
}

void ft_cant_clear(int ac, char **av, t_data *data)
{
	data->philo_num = ft_atoi(av[1]);
	data->philo_span = ft_atoi(av[2]);
	data->philo_eat = ft_atoi(av[3]);
	data->philo_sleep = ft_atoi(av[4]);
	data->philo_clear = -1;
}