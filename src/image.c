#include "./../include/so_long.h"

void	ft_destroy_image(t_data *data)
{
	mlx_destroy_image(data->mlx_p, data->brick);
	mlx_destroy_image(data->mlx_p, data->chimney);
	mlx_destroy_image(data->mlx_p, data->player);
	mlx_destroy_image(data->mlx_p, data->star);
	mlx_destroy_image(data->mlx_p, data->grass);

}

void	ft_img_setting(t_data *data)
{
    int size;

    size = 32;
    data->brick = mlx_xpm_file_to_image(data->mlx_p, "./../img/brick.xpm", &size, &size);
    data->grass = mlx_xpm_file_to_image(data->mlx_p, "./../img/grass.xpm", &size, &size);
    if (data->player_aspect == 'L')
        data->player = mlx_xpm_file_to_image(data->mlx_p, "./../img/player_left.xpm", &size, &size);
    if (data->player_aspect == 'F')
        data->player = mlx_xpm_file_to_image(data->mlx_p, "./../img/player_front.xpm", &size, &size);
    if (data->player_aspect == 'B')
        data->player = mlx_xpm_file_to_image(data->mlx_p, "./../img/player_back.xpm", &size, &size);
    if (data->player_aspect == 'R')
        data->player = mlx_xpm_file_to_image(data->mlx_p, "./../img/player_right.xpm", &size, &size);
    data->chimney = mlx_xpm_file_to_image(data->mlx_p, "./../img/chimney.xpm", &size, &size);
    data->star = mlx_xpm_file_to_image(data->mlx_p, "./../img/star.xpm", &size, &size);
}
