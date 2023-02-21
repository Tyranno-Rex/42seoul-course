#include "philosopher.h"


static void ft_philo_run(t_data *data);

int main(int ac, char **av)
{
	t_data data;

	ft_check_ac_av(ac, av, &data);
	ft_philo_run(&data);
}