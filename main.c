#include "so_long.h"

static int	ft_end_game(t_data *data)
{
	mlx_destroy_window(data->mlx_p, data->mlx_w);
	ft_printf("game end!");
	exit(EXIT_FAILURE);
}

static int	ft_player_controller(int wasd, t_data *data)
{
	if (wasd == 53)
		ft_end_game(data);
	if (wasd == W || wasd == UP || wasd == A || wasd == LEFT ||
		wasd == S || wasd == DOWN || wasd == D || wasd == RIGHT)
	{
		ft_destroy_image(data);
		ft_player_update(wasd, data);
		ft_img_setting(data);
		ft_draw_window(data);
	}
	return (1);
}

/* 함수 설명 :
계속해서 실행되는 함수로 이 프로그램의 메인 함수이다.
1. 맵을 읽어 드리고, 맵의 2차원 배열의 값을 반환한다.
2. 맵이 게임에 이용 가능한 형태인지 확인한다.
3. 맵을 수정가능한 카피맵을 하나 만든다 -> 이는 맵의 유효성 체크를 위해 만드는 것이다.
4. 플레이어의 위치를 반환하는 함수를 통해 플레이어의 위치를 체크한다.
5. 해당 맵이 클리어 가능한지 확인한다. (flood_fill 알고리즘을 통해서 맵을 수정한다).
6. 맵이 클리어가 가능하다면, g_data의 map에 map을 넣는다.
7. 메인 구조체에 대한 초기화를 진행한다.
8. 기반 자료를 모두 채웠기 때문에 이를 활용해서 윈도우를 그린다.
*/
static void	ft_run_solong(const char *map_path)
{
	t_data		g_data;
	t_map		g_element;
	char		**map;
	char		**map_check;
	int			*xy;

	map = ft_read_map(map_path);
	ft_map_validator((const char **)map, &g_element);
	map_check = ft_copymap((const char **)map);
	xy = ft_player_pos((const char **)map_check);
	g_element.character_x = xy[0];
	g_element.character_y = xy[1];
	ft_check_map_clear(map_check, xy[0], xy[1]);
	g_data.map = map;
	ft_struct_init(&g_data, &g_element);
	ft_draw_window(&g_data);
	mlx_hook(g_data.mlx_w, 2, 0, ft_player_controller, &g_data);
	mlx_hook(g_data.mlx_w, 17, 0, ft_end_game, &g_data);
	mlx_loop(g_data.mlx_p);
}

// av 입력 값이 2개인지, .ber 형식의 맵이 입력이 되었는지 확인한다.
void ft_check_av(int ac, char **av)
{
	if (ac != 2 || ft_strnstr(av[1], ".ber", ft_strlen(av[1]) == 0))
	{
		if (ac != 2)
			ft_printf("ac must be two, your ac isn't two");
		else
			ft_printf("your map format must be \".ber\"");
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	ft_check_av(ac, av);	
	ft_run_solong(av[1]);
}

