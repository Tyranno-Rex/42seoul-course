#include "./../include/so_long.h"

void ft_struct_init(t_data *data, t_map *g_element)
{
    int wh;

    wh = 32;
    data->wh = 32;
    data->map_w = ft_strlen(data->map[0]) * 32;
    data->map_h = ft_map_height(data->map) * 32;
    data->mlx_p = mlx_init();
    data->mlx_w = ft_create_window(&data);
    data->moves_counter = 0;
    data->player_aspect = 'L';
    data->star_total = g_element->star;
    data->px = g_element->character_x;
    data->py = g_element->character_y;
    ft_img_setting(&data);
}
