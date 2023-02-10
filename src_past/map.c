#include "./../include/so_long.h"

int	ft_check_wall(char *av, unsigned int *width, unsigned int *height, int len)
{
	char	*line;
	char	*lineb;
	int		fd;

	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL || line[0] = '\n')
		return(1);
    
	

	line = get_next_line(fd)
}

void ft_check_map_PEC(char *av);


/*맵이 잘못 되는 지 확인
각각의 게임의 요소들을 하나하나 확인
1. 벽으로 둘러쌓였는지 확인
2. 출구와 플레이어 별을 가지고 있는 지 확인
3. 출구와 플레이어가 1개씩만 있는 지 확인
4. 잘못된 문자열이 있는 지 확인*/
int ft_check_what_is_wrong(char *av)
{
    unsigned int width; // 가로
    unsigned int height; // 세로
	int error;

	error = ft_check_wall(av);
	ft_check_PEC();
}

char	**ft_read_map(const char *path)
{
	int		fd;
	char	*curr_line;
	char	*map_content;
	char	**map_tab;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	curr_line = get_next_line(fd);
	if (curr_line && *curr_line == '\n')
		ft_show_error("The map isn't in shape!");
	map_content = NULL;
	while (curr_line)
	{
		ft_check_map_lines(curr_line);
		map_content = ft_call_strjoin(map_content, curr_line);
		free(curr_line);
		curr_line = NULL;
		curr_line = get_next_line(fd);
	}
	map_tab = ft_split(map_content, '\n');
	free(map_content);
	close(fd);
	return (map_tab);
}

// 잘못되었다면 게임을 종료하고 잘 되었다면 게임을 실행함.
void	ft_check_map(char *av)
{
	if (ft_check_what_is_wrong(av) == 1)
	{
		ft_printf("then exit game!");
		exit(EXIT_FAILURE);
	}
	else if (ft_check_what_is_wrong(av) == 2)
		ft_printf("Let's go!");
}
