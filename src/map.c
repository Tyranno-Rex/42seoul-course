#include "./../include/so_long.h"


void ft_map_init(char **map_data, t_data *data)
{
    int fd;

    fd = open(map_data[1], 0);
    if (fd < 0)
    {
        ft_printf()
    }
}

void	ft_window_size(t_data *data, char **argv)
/* will find the window size and check for some errors */
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nInvalid map_path/map\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		printf("Error\nmap has to be .ber\n");
		exit(EXIT_FAILURE);
	}
	data->size_x = (ft_line_length(fd) * IMG_W);
	data->size_y = (ft_count_lines(fd, data->size_x, IMG_W) * IMG_H);
}