#include "./../include/so_long.h"

void    ft_put_img(char c)
{
    if ()
}

void    ft_draw_window(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '1')
                ft_put_img();
            else if (map[i][j] == "0")
                ft_put_img();
            else if (map[i][j] == "C")
                ft_put_img();
            else if (map[i][j] == "P")
                ft_put_img();
            else if (map[i][j] == "E")
                ft_put_img();
            j++;
        }
        i++;
    }
    
}