#include "philosopher.h"

void    ft_check_av_number(char *av)
{
	int i;

	i = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]) == 0)
			ft_showe_error("your input blended with character\n");
		i++;
	}
}

void ft_check_ac_av(int ac, char **av)
{
	int i = 0;

	if (ac != 5 && ac != 6)
		ft_showe_error("your ac is wrong. ac must be 5~6.\n");
	while (++i < ac)
	{
		ft_check_av_number(av[i]);
		if (ft_atoi(av[i]) < 0)
			ft_showe_error("your ac is wrong");
	}
}