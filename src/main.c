#include "philosopher.h"




void ft_run_simulator(t_data *data)
{
	mutex_lock()
	data->
}


int		ft_init_mutex(int ac, char **av, t_data *data)
{
	int philo_num = data->total_philo;
	data->fork = (pthread_mutex_t)malloc(sizeof(pthread_mutex_t) * philo_num);
	if (!data->fork)
		return (1);
	
}

int		ft_init_data(int ac, char **av, t_data *data)
{
	data->total_philo = ft_atoi(av[1]);
	data->dead_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->goal_of_eat = ft_atoi(av[5]);
	data->alive = 0;
	if (data->total_philo <= 0 || data->dead_time <= 0
	|| data->eat_time < 0 || data->sleep_time < 0)
	{
		ft_showe_error("your input wrong value");
		free(data);
		return (1);
	}
	return (0);
}


int main(int ac, char **av)
{
	t_data		*data;
	int			i;

	i = 0;
	ft_check_ac_av(ac, av);
	if (ft_init_data(ac, av, &data) || ft_init_mutex(ac, av, &data))
		return (0);
	ft_run_simulator(&data);	
}
