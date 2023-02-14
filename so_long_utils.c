#include "so_long.h"

int	ft_strlen_n(const char *str, char c)
{
	int		the_num;

	the_num = 0;
    if (c == '\n')
    {
	    while (*str != '\n')
        {
            the_num++;
            str++;
        }
    }
    if (c == '\0')
    {
        while (*str != '\0')
        {
            the_num++;
            str++;
        }
    }
	return (the_num);
}

void	ft_show_error(const char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd((char *)msg, 2);
	exit(1);
}

void	ft_finish_game(t_data *data)
{
	if (data->nb_collec == 0)
	{
		mlx_destroy_window(data->mlx_p, data->mlx_w);
		ft_printf("Game Finished, you win!");
		exit(0);
	}
}