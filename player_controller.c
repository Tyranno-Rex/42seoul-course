
#include "so_long.h"

static void	ft_go_left(t_data *data)
{
	data->aspect = 'L';
	if (data->map[data->py][data->px - 1] == '0')
	{
		data->map[data->py][data->px] = '0';
		data->map[data->py][--data->px] = 'P';
		ft_printf("Move: %d\n", ++data->moves_counter);
	}
	else if (data->map[data->py][data->px - 1] == 'C')
	{
		data->map[data->py][data->px] = '0';
		data->map[data->py][--data->px] = 'P';
		ft_collect(data);
	}
	else if (data->map[data->py][data->px - 1] == 'E')
		ft_finish_game(data);
}

static void	ft_go_right(t_data *data)
{
	data->aspect = 'R';
	if (data->map[data->py][data->px + 1] == '0')
	{
		data->map[data->py][data->px] = '0';
		data->map[data->py][++data->px] = 'P';
		ft_printf("Move: %d\n", ++data->moves_counter);
	}
	else if (data->map[data->py][data->px + 1] == 'C')
	{
		data->map[data->py][data->px] = '0';
		data->map[data->py][++data->px] = 'P';
		ft_collect(data);
	}
	else if (data->map[data->py][data->px + 1] == 'E')
		ft_finish_game(data);
}

static void	ft_go_down(t_data *data)
{
	data->aspect = 'B';
	if (data->map[data->py + 1][data->px] == '0')
	{
		data->map[data->py][data->px] = '0';
		data->map[++data->py][data->px] = 'P';
		ft_printf("Move: %d\n", ++data->moves_counter);
	}
	else if (data->map[data->py + 1][data->px] == 'C')
	{
		data->map[data->py][data->px] = '0';
		data->map[++data->py][data->px] = 'P';
		ft_collect(data);
	}
	else if (data->map[data->py + 1][data->px] == 'E')
		ft_finish_game(data);
}

static void	ft_go_up(t_data *data)
{
	data->aspect = 'F';
	if (data->map[data->py - 1][data->px] == '0')
	{
		data->map[data->py][data->px] = '0';
		data->map[--data->py][data->px] = 'P';
		ft_printf("Move: %d\n", ++data->moves_counter);
	}
	else if (data->map[data->py - 1][data->px] == 'C')
	{
		data->map[data->py][data->px] = '0';
		data->map[--data->py][data->px] = 'P';
		ft_collect(data);
	}
	else if (data->map[data->py - 1][data->px] == 'E')
		ft_finish_game(data);
}

void	ft_move_player(int keycode, t_data *data)
{
	if (keycode == W || keycode == UP)
		ft_go_up(data);
	else if (keycode == A || keycode == LEFT)
		ft_go_left(data);
	else if (keycode == D || keycode == RIGHT)
		ft_go_right(data);
	else if (keycode == S || keycode == DOWN)
		ft_go_down(data);
}
