#include "./../include/so_long.h"

int	*ft_choose_xy(const char **map)
{
	int			x;
	int			y;
	int			*xy;

	y = 0;
	xy = (int *)ft_calloc(2, sizeof(int));
	if (!xy)
		ft_show_error("Allocation of the fake map failed!");
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