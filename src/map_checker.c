#include "./../include/so_long.h"

/*맵의 가장자리에 대한 유효성을 검증하는 함수
1. 가로의 길이와 세로의 길이를 구해준다.
2. while문을 통해서 맵을 전체를 확인한다 
  -> 4가지 중 하나만 선택이 되어도 검사한다.
  -> 가로 위치가 0 또는 최대 높이이거나, 세로 위치가 0이거나 최대 너비이면 검사한다.
  -> 1이 아니라면 이는 틀렸다. 
*/
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
            if (i == 0 || j == 0 || i == height || j == width)
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
    ft_check_element_init(g_element);
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            ft_check_what(g_element, map[i][j]);
            j++;
        }
        i++;
    }
    ft_check_character_2(g_element);
}
