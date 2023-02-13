#include "so_long.h"

void	ft_flood_fill(char **map, int x, int y)
{
	if (x < 0 || x >= (int)ft_strlen(map[0]) || y < 0
		|| y >= ft_map_height((const char **)map) || map[y][x] == '1'
		|| map[y][x] == 'V' || map[y][x] == 'E')
		return ;
	if (map[y][x] != 'P')
		map[y][x] = 'V';
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x, y - 1);
	ft_flood_fill(map, x, y + 1);
}

void	ft_check_can_clear(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				ft_printf("Something wrong with valid path!");
				exit(EXIT_FAILURE);
			}
			if (map[i][j] == 'E' && map[i - 1][j] != 'V' && map[i + 1][j] != 'V'
			&& map[i][j - 1] != 'V' && map[i][j + 1] != 'V')
			{
				ft_printf("Something wrong with valid path!");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}


void ft_check_map_clear(char **map, int x, int y)
{
	ft_flood_fill(map, x, y);
	ft_check_can_clear(map);
}