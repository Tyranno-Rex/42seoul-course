#include "./../include/so_long.h"

void ft_strput_matrix(t_data *data, char *av, int ac)
{
    char	buffer[2];
    int		index;
	int		byte;
	int		fd;

	index = 0;
	byte = 1;
	buffer[1] = '\0';
	fd = open(av[1], O_RDONLY);
	while (byte == 1)
	{
		byte = read(fd, buffer, 1);
		if (byte != 1)
			break;
		if (buffer[0] != '\n' && buffer[0] != '\0')
			data->map->map[index] = ft_strjoin(data->map->map[index], buffer);
		else
			index++;
	}
	ft_check_board(data);
}