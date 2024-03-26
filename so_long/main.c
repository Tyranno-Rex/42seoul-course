/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:37:13 by eunjeong          #+#    #+#             */
/*   Updated: 2023/02/18 12:37:40 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_close_game(t_data *data)
{
	mlx_destroy_window(data->mlx_p, data->mlx_w);
	exit(0);
}

static int	ft_player_controller(int keycode, t_data *data)
{
	if (keycode == 53)
		ft_close_game(data);
	if (keycode == A || keycode == LEFT
		|| keycode == D || keycode == RIGHT
		|| keycode == S || keycode == DOWN
		|| keycode == W || keycode == UP)
	{
		ft_destory_images(data);
		ft_move_player(keycode, data);
		ft_load_images(data);
		ft_draw_characters(data);
	}
	return (1);
}

static void	ft_run_solong(const char *map_path)
{
	t_data		data;
	t_map		m_data;
	char		**map;
	char		**map_check;
	int			*xy;

	map = ft_read_map(map_path);
	ft_struct_initializer_2(&m_data);
	ft_map_validator((const char **)map, &m_data);
	map_check = ft_copymap((const char **)map);
	xy = ft_choose_xy((const char **)map_check);
	ft_flood_fill(map_check, xy[0], xy[1]);
	ft_check_validpath((const char **)map_check);
	free(map_check);
	free(map_check);
	data.map = map;
	ft_struct_initializer(&data);
	ft_draw_characters(&data);
	mlx_hook(data.mlx_w, 2, 0, ft_player_controller, &data);
	mlx_hook(data.mlx_w, 17, 0, ft_close_game, &data);
	mlx_loop(data.mlx_p);
}

void	ft_check_av(int ac, char **av)
{
	if (ac != 2)
		ft_show_error("ac must be two, your ac isn't two");
	ft_check_ber(av[1]);
}

void	check_leak(void)
{
	system("leaks --list -- so_long");
}

int	main(int ac, char **av)
{
	atexit(check_leak);
	ft_check_av(ac, av);
	ft_run_solong(av[1]);
}
