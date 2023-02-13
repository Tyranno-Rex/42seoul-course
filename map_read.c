#include "so_long.h"

static char	*ft_static_strjoin(char *s1, char *s2)
{
	char	*result;

	if (!s1)
		s1 = ft_strdup("");
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

// void ft_check_line_len(int fd, int len, char *map_return, char *line)
// {
// 	int i;

// 	while (line != NULL)
// 	{
// 		i = ft_strlen(line);
// 		if (i != len)
// 		{
// 			ft_printf("map's width isn't right");
// 			exit(EXIT_FAILURE);
// 		}
// 		map_return = ft_static_strjoin(map_return, line);
// 		free(line);
// 		line = NULL;
// 		line = get_next_line(fd);
// 	}
// }


void ft_check_line_len(char *line, int len)
{
	int i;
	i = ft_strlen(line);
	if (i != len)
	{
		ft_printf("your map width isn't right!");
		exit(EXIT_FAILURE);
	}
}

/*맵을 읽어서 이차원 char 배열로 반환하는 함수이다.
1. 파일을 열어 읽는다.
2. 한줄을 가져오기 때문에 while문을 돌면서 line이 반환되지 않을 때까지 진행한다.
3. 한줄씩 가져온 라인 데이터를 이차원 배열에 넣는다.
4. 해당 함수는 '\n'을 문자열로 가지고 있기 때문에 \n를 제거한후에 2차원 배열로 넣어준다.
*/
char	**ft_read_map(const char *path)
{
	int		fd;
	int		line_len;
	char	*line;
	char	*map_content;
	char	**map_tab;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL && *line == '\n')
	{
		ft_printf("The map isn't in shape!");
		exit(EXIT_FAILURE);
	}
	map_content = NULL;
	line_len = ft_strlen(line);
	// if 	(ft_check_line_len(fd, line_len, map_content, line) == 1)
	// 	exit(EXIT_FAILURE);

	// 이거 체크해야함.
	// ft_check_map_lines(line);
	while (line != NULL)
	{
		ft_check_line_len(line, line_len);
		map_content = ft_static_strjoin(map_content, line);
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	map_tab = ft_split(map_content, '\n');
	free(map_content);
	close(fd);
	return (map_tab);
}
