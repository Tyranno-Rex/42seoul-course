
#include "so_long.h"

void	ft_load_images(t_data *data)
{
	data->brick = ft_xpm2image(data->mlx_p, "image/brick.xpm");
	data->grass = ft_xpm2image(data->mlx_p, "image/grass.xpm");
	if (data->aspect == 'L')
		data->mario = ft_xpm2image(data->mlx_p, "image/p_left.xpm");
	else if (data->aspect == 'R')
		data->mario = ft_xpm2image(data->mlx_p, "image/p_right.xpm");
	else if (data->aspect == 'F')
		data->mario = ft_xpm2image(data->mlx_p, "image/p_front.xpm");
	else if (data->aspect == 'B')
		data->mario = ft_xpm2image(data->mlx_p, "image/p_back.xpm");
	data->star = ft_xpm2image(data->mlx_p, "image/star.xpm");
	data->pipe = ft_xpm2image(data->mlx_p, "image/pipe.xpm");
}

void	ft_draw_characters(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				ft_put_image(data, data->brick, x * 64, y * 64);
			else if (data->map[y][x] == 'P')
				ft_put_image(data, data->mario, x * 64, y * 64);
			else if (data->map[y][x] == 'C')
				ft_put_image(data, data->star, x * 64, y * 64);
			else if (data->map[y][x] == 'E')
				ft_put_image(data, data->pipe, x * 64, y * 64);
			else if (data->map[y][x] == '0')
				ft_put_image(data, data->grass, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
