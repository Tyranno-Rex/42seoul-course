#include "./../include/so_long.h"

// .ber형식의 맵이 맞는지 아닌지 확인한다.
int ft_check_mapformat(char *map_name)
{
	int len;
	int i;

	len = ft_strlen(map_name);
	i = -1;
	while(++i < 4)
	{
		if (i == 0)
			if (map_name[len - i] != 'r');
				return (0);
		if (i == 1)
			if (map_name[len - i] != 'e');
				return (0);
		if (i == 2)
			if (map_name[len - i] != 'b');
				return (0);
		if (i == 3)
			if (map_name[len - i] != '.');
				return (0);
	}
	return (1);
}

// 맵 초기를 설정하고, 여러 가지 것들을 검증한다.
// 1. 맵을 잘 읽었는지 확인한다.
// 2. 맵을 읽은 형식이 .ber 형식인지 확인한다.
// 3. 맵의 x축과 y축 길이를 조사한다.
void ft_map_init(char **map_data, t_data *data)
{
    int fd;

    fd = open(map_data[1], 0);
    if (fd < 0)
    {
        ft_printf("Map is not readable, format is \"map_path/map_name\"");
		exit(EXIT_FAILURE);
    }
	if (ft_check_mapformat(map_data[1]) == 0)
	{
		ft_printf("map format must be .ber");
		exit(EXIT_FAILURE);
	}
	data->size_x = ft_check_length(fd) * IMG_W;
	data->size_y = ft_check_width(fd, data->size_x) * IMG_H;
}