#include "./../include/so_long.h"

int ft_put_img(t_data *data, void *img, int x, int y)
{
    void *mlx_p;
    void *win_p;

    mlx_p = data->mlx_p;
    win_p = data->mlx_w;
    return (mlx_put_image_to_window(mlx_p, win_p, img, x * 32, y * 32));
}

void    ft_draw_window(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == '1')
                ft_put_img(&data, data->brick, j, i);
            else if (data->map[i][j] == "0")
                ft_put_img(&data, data->grass, j, i);
            else if (data->map[i][j] == "C")
                ft_put_img(&data, data->star, j, i);
            else if (data->map[i][j] == "P")
                ft_put_img(&data, data->player, j, i);
            else if (data->map[i][j] == "E")
                ft_put_img(&data, data->chimney, j, i);
            j++;
        }
        i++;
    }
    
}