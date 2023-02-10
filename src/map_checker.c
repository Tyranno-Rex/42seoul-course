#include "./../include/so_long.h"

void ft_check_border(const char **map)
{
    int width;
    int height;
    int i;
    int j;

    i = 0;
    width = ft_strlen(map[0]) - 1;
    height = ft_map_height((const char**)map) - 1;
    while (map[i])
    {
        while (map[i][j])
        {
            j = 0 ;
            if (i == 0 || j == 0 || j == height || i == width)
                if (map[i][j] != '1')
                {
                    ft_printf("map's border is wrong!");
                    exit(EXIT_FAILURE);
                }
            j++;
        }
        i++;
    }
}

// 각 요소가 몇 개 있는 지 확인하는 과정이다.
void ft_check_what(t_map *check, char element)
{
    int     i;

    if (element == '1' || element == '0')
        i = 1;
    else if (element == 'p')
        check->character += 1;
    else if (element == 'C')
        check->star += 1;
    else if (element == 'E')
        check->exit += 1;
    else
    {
        ft_printf("your map elements have another letter!");
        exit(EXIT_FAILURE);
    }
    if (check->character > 1 || check->exit > 1)
    {
        ft_printf("your map element is wrong");
        exit(EXIT_FAILURE);
    }
}

void ft_check_character_2(t_map *check)
{
    if (check->character != 1)
    {
        ft_printf("character element must be one");
        exit(EXIT_FAILURE);
    }
    if (check->exit != 1)
    {
        ft_printf("exit element must be one!");
        exit(EXIT_FAILURE);
    }
}

void ft_check_element_init(t_map *check)
{
    check->character = 0;
    check->exit = 0;
    check->star = 0;
}

void ft_check_character(const char **map, t_map *g_element)
{
    int i;
    int j;

    i = 0;
    ft_check_element_init(&g_element);
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            ft_check_what(&g_element, map[i][j]);
            j++;
        }
        i++;
    }
    ft_check_character_2(&g_element);
}
