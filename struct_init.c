#include "so_long.h"

static int	ft_player_pos(const char **map, char xy)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' && xy == 'x')
				return (j);
			else if (map[i][j] == 'P' && xy == 'y')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_struct_initializer(t_data *data)
{
	int	wh;

	wh = 32;
	data->map_w = ft_strlen_n(data->map[0], '\n') * 1.5;
	data->map_h = ft_tab_size((const char **)data->map) * 64;
	data->wh = wh;
	data->mlx_p = mlx_init();
	if (!data->mlx_p)
		ft_show_error("mlx_init function fails!");
	data->mlx_w = ft_new_window(data);
	data->aspect = 'L';
	data->nb_collec = ft_count_collect((const char **)data->map);
	data->px = ft_player_pos((const char **)data->map, 'x');
	data->py = ft_player_pos((const char **)data->map, 'y');
	data->moves_counter = 0;
	ft_load_images(data);
}

void	ft_struct_initializer_2(t_map *m_data)
{
	m_data->character = 0;
	m_data->character_x = 0;
	m_data->character_y = 0;
	m_data->star = 0;
	m_data->exit = 0;
}