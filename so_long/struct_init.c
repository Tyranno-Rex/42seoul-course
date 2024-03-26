/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:39:20 by eunjeong          #+#    #+#             */
/*   Updated: 2023/02/18 12:39:25 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	wh = 64;
	data->map_w = ft_strlen_pro(data->map[0], '\n') * 64;
	data->map_h = ft_tab_size((const char **)data->map) * 64;
	data->wh = wh;
	data->mlx_p = mlx_init();
	if (!data->mlx_p)
		ft_show_error("mlx_init function fails!");
	data->mlx_w = ft_new_window(data);
	data->aspect = 'R';
	data->nb_collec = ft_count_collect((const char **)data->map);
	data->px = ft_player_pos((const char **)data->map, 'x');
	data->py = ft_player_pos((const char **)data->map, 'y');
	data->moves_counter = 0;
	ft_load_images(data);
}

void	ft_struct_initializer_2(t_map *m_data)
{
	m_data->character = 0;
	m_data->star = 0;
	m_data->exit = 0;
}
