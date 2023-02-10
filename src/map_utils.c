#include "./../include/so_long.h"

int     ft_map_height(const char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        i++;
    }
    return (i);
}

void ft_map_validator(const char **map)
{
    if (!map)
    {
        ft_printf("map is nnot allocated!");
        exit(EXIT_FAILURE);
    }
    ft_check_border((const char **) map);
    ft_check_character((const char **) map);
}


// int ft_strlen_pro

// void ft_show_error

