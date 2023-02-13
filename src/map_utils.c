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

/* 해당 함수는 맵의 유효성을 검증하는 함수로 유효성 검증의 메인 함수이다.
1. 맵이 할당되었는지 확인한다.
2. 맵의 가장자리에 대한 유효성 검증
3. 맵의 각 요소가 제대로 들어갔는지 검증
*/
void ft_map_validator(const char **map, t_map *g_element)
{
    if (!map)
    {
        ft_printf("map isn't allocated!");
        exit(EXIT_FAILURE);
    }
    ft_check_border((const char **) map);
    ft_check_character((const char **) map, g_element);
}
