#include "philosopher.h"

static void ft_philo_eat_and_sleep(t_data *data)
{
	pthread_mutex_lock(data->fork);
	usleep(data->philo_eat);
	pthread_mutex_unlock(data->fork);
	usleep(data->philo_sleep);
}

static void ft_philo_run(t_data *data)
{
	int i = -1;

	while (++i < num)
	{
		if (pthread_create(&philo[i], NULL, ft_philo_eat_and_sleep, data));
			ft_showe_error("thread creat error!");
	}
	pthread_detach(&philo[i]);
}

int main(int ac, char **av)
{
	t_data		*data;
	int			i;

	i = 0;
	// ft_check_ac_av(ac, av, &data);
	// data.fork = (pthread_mutex_t)malloc(sizeof(pthread_mutex_t) * ac);
	// if (!data.fork)
	// 	printf("error malloc isn't allocated");
	// else
	// 	printf("malloc is allocated");
	// while (i < ac - 1)
	// {
	// 	printf("pthread is allocated!");
	// 	pthread_mutex_init(&data.fork[i], NULL);
	// 	i++;
	// }
	// ft_philo_run(&data, fork);
}