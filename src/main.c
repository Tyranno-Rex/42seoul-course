#include "philosopher.h"

static void ft_philo_eat_and_sleep(t_data *data)
{
	pthread_mutex_lock(fork);
	usleep(data->philo_eat);
	pthread_mutex_unlock(fork);
	usleep(data->philo_sleep);
}

static void ft_philo_run(t_data *data)
{
	int num = data->philo_num;
	int i = -1;
	pthread_t philo[num];

	if (pthread_mutex_init(&fork, NULL) == 0)
		ft_showe_error("Mutex init failed");
	while (++i < num)
	{
		if (pthread_create(&philo[i], NULL, ft_philo_eat_and_sleep, data));
			ft_showe_error("thread creat error!");
	}
	pthread_detach(&philo[i]);
}

int main(int ac, char **av)
{
	t_data data;
	pthread_mutex_t fork;
	ft_check_ac_av(ac, av, &data, fork);
	ft_philo_run(&data);
}