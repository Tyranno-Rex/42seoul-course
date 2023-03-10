#include "philosopher.h"

void    ft_check_av_number(char *av)
{
	int i;

	i = 0;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			ft_showe_error("your input blended with character, av must be only number");
		i++;
	}
}

void ft_check_ac_av(int ac, char **av, t_data *data, pthread_mutex_t fork)
{
	int i = 0;

	while (++i < ac)
		ft_check_av_number(av[i]);
	if (ac == 5)
		ft_cant_clear(ac, av, data);
	else if (ac == 6)
		ft_can_clear(ac, av, data);
	else
		ft_showe_error("your ac is wrong");
}