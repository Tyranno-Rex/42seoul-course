#include "./../include/so_long.h"

int	*ft_player_pos(const char **map)
{
	int			x;
	int			y;
	int			*xy;

	y = 0;
	xy = (int *)ft_calloc(2, sizeof(int));
	if (!xy)
	{
		ft_printf("Allocation of the fake map failed!");
		exit(EXIT_FAILURE);
	}
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				xy[0] = x;
				xy[1] = y;
				break ;
			}
			x++;
		}
		y++;
	}
	return (xy);
}