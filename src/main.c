#include "philosopher.h"

int		ft_init_mutex(int ac, char **av, t_data *data)
{
	int			i;
	int 		philo_num;

	i = -1;
	philo_num = data->total_philo;
	data->eat_time = (pthread_mutex_t)malloc(sizeof(pthread_mutex_t)* philo_num);
	data->fork = (pthread_mutex_t)malloc(sizeof(pthread_mutex_t)* philo_num);
	if (!data->fork)
		return (1);
	while (++i < data->total_philo)
	{
		if (!pthread_mutex_init(&data->fork[i], NULL))
			ft_showe_error("fork isn't made");
		if (!pthread_mutex_init(&data->eat_time[i], NULL))
			ft_showe_error("eat_time isn't made");
	}
	if (pthread_mutex_init(&data->alive_mutex, NULL))
		ft_showe_error("alive mutex is'nt made");
	return (0);
}

int		ft_init_data(int ac, char **av, t_data *data)
{
	data->total_philo = ft_atoi(av[1]);
	data->dead_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->goal_of_eat = ft_atoi(av[5]);
	else
		data->goal_of_eat = -1;
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


int ft_check_alive(t_data *data)
{
	int check;

	if (pthread_mutex_lock(&data->alive))
		return (-1);
	chekc = data->alive;
	if (pthread_mutex_unlock(&data->alive))
		return (-1);
	return (check);
}


void 	*launch_thread(void *content)
{
	t_philo 		*ph;
	struct timeval	time;

	ph = (t_philo *)content;
	while (!ft_check_alive(ph->data))
	{
		if (ft_manage_fork(ph) || pthread_mutex_lock(&data->data->))
	}
		
}


void ft_run_simulator(t_data *data)
{
	int i;

	i = -1;
	data->philo = (t_philo *)malloc(sizeof(t_philo) * (data->total_philo));
	if (!data->philo || ft_init_eat_time(data))
		return (1);
	while (++i < data->total_philo)
	{
		data->philo.name = i;
		data->philo->how_many_eat = data->how_many_;
		data->philo->data = data;
		if (pthread_create(&data->philo[i].thread))
	}

	
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
