#include "./../include/so_long.h"


void *ft_create_window(t_data *data)
{
    void *R_ptr;

    R_ptr = mlx_new_window(data->mlx_p, data->map_w, data->map_h, "so_long");
    if (!R_ptr)
    {
        ft_printf("mlx_allocation is fault");
        exit(EXIT_FAILURE);
    }
    return (R_ptr);
}