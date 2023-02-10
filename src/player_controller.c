#include "./../include/so_long.h"

static void	ft_player_front(t_data *data)
{
    data->player_aspect = 'F';
	if (data->map[data->py - 1][data->px] == '0')
	{
		data->map[data->py][data->px] = '0';
		data->map[--data->py][data->px] = 'P';
		ft_printf("you move : %d\n", ++data->moves_counter);
	}
	else if (data->map[data->py - 1][data->px] == 'C')
	{
		data->map[data->py][data->px] = '0';
		data->map[--data->py][data->px] = 'P';
		ft_star_collect(data);
	}
	else if (data->map[data->py - 1][data->px] == 'E')
		ft_check_finish(data);
}

static void	ft_player_left(t_data *data)
{
	data->player_aspect = 'L';
	if (data->map[data->py][data->px - 1] == '0')
	{
		data->map[data->py][data->px] = '0';
		data->map[data->py][--data->px] = 'P';
		ft_printf("you move : %d\n", ++data->moves_counter);
	}
	else if (data->map[data->py][data->px - 1] == 'C')
	{
		data->map[data->py][data->px] = '0';
		data->map[data->py][--data->px] = 'P';
		ft_star_collect(data); 
	}
	else if (data->map[data->py][data->px - 1] == 'E')
		ft_check_finish(data);
}

static void	ft_player_down(t_data *data)
{
    data->player_aspect = 'B';
	if (data->map[data->py + 1][data->px] == '0')
	{
		data->map[data->py][data->px] = '0';
		data->map[++data->py][data->px] = 'P';
		ft_printf("you move : %d\n", ++data->moves_counter);
	}
	else if (data->map[data->py + 1][data->px] == 'C')
	{
		data->map[data->py][data->px] = '0';
		data->map[++data->py][data->px] = 'P';
		ft_star_collect(data);
	}
	else if (data->map[data->py + 1][data->px] == 'E')
		ft_check_finish(data);
}

static void	ft_player_right(t_data *data)
{
	data->player_aspect = 'R';
	if (data->map[data->py][data->px + 1] == '0')
	{
		data->map[data->py][data->px] = '0';
		data->map[data->py][++data->px] = 'P';
		ft_printf("you move : %d\n", ++data->moves_counter);
	}
	else if (data->map[data->py][data->px + 1] == 'C')
	{
		data->map[data->py][data->px] = '0';
		data->map[data->py][++data->px] = 'P';
		ft_star_collect(data);
	}
	else if (data->map[data->py][data->px + 1] == 'E')
		ft_check_finish(data);
}

void	ft_player_update(int keycode, t_data *data)
{
	if (keycode == W || keycode == UP)
		ft_player_front(data);
	else if (keycode == A || keycode == LEFT)
		ft_player_left(data);
	else if (keycode == S || keycode == DOWN)
		ft_player_down(data);
	else if (keycode == D || keycode == RIGHT)
		ft_player_right(data);
}