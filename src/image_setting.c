#include "./../include/so_long.h"

void	ft_img_setting(t_data *data)
{
    int size;

    size = 32;
    data->brick = mlx_xpm_file_to_image(data->mlx_p, "./../img/brick.xpm", &size, &size);
    data->grass = mlx_xpm_file_to_image(data->mlx_p, "./../img/grass.xpm", &size, &size);
    data->player = mlx_xpm_file_to_image(data->mlx_p, "./../img/player_front.xpm", &size, &size);
    data->chimney = mlx_xpm_file_to_image(data->mlx_p, "./../img/chimney.xpm", &size, &size);
    data->star = mlx_xpm_file_to_image(data->mlx_p, "./../img/star.xpm", &size, &size);
}
