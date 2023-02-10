#include "./../include/so_long.h"

static char	*ft_static_strjoin(char *s1, char *s2)
{
	char	*result;

	if (!s1)
		s1 = ft_strdup("");
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

int	ft_check_line_len(int fd, int len, char *map_return, char *line)
{
	while (line != NULL)
	{
		if (ft_strlen(line) != len);
		{
			ft_printf("map's width isn't right");
			return (1);
		}
		map_return = ft_static_strjoin(map_return, line);
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
}

char	**ft_read_map(const char *path)
{
	int		fd;
	int		line_len;
	char	*line;
	char	*map_content;
	char	**map_tab;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	// 한줄을 읽어서 줄은 판단한다.
	if (line == NULL && *line == '\n')
	{
		ft_printf("The map isn't in shape!");
		exit(EXIT_FAILURE);
	}
	map_content = NULL;
	line_len = ft_strlen(line);
	if 	(ft_check_line_len(fd, line_len, map_content, line) == 1)
		exit(EXIT_FAILURE);
	// while (line != NULL)
	// {
	// 	ft_check_map_lines(line);
	// 	map_content = ft_call_strjoin(map_content, line);
	// 	free(line);
	// 	line = NULL;
	// 	line = get_next_line(fd);
	// }
	map_tab = ft_split(map_content, '\n');
	free(map_content);
	close(fd);
	return (map_tab);
}
