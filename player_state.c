#include "so_long.h"

void	ft_star_collect(t_data *data)
{
	data->star_total--;
	ft_printf("Move Number: %d\n", ++data->moves_counter);
}

void	ft_check_finish(t_data *data)
{
	if (data->star_total == 0)
	{
		mlx_destroy_window(data->mlx_p, data->mlx_w);
		ft_printf("you clear the game! perfect!");
		exit(0);
	}
}
