#include "./../include/so_long.h"

/*맵의 가로 길이 체크하는 함수*/
int ft_check_lenght(int fd)
{
    char	tmp[1];
    int		len;
	int		byte;

	tmp[0] = '\0';
	len = 0;
	byte = 1;
	
	while (1)
	{
		byte = read(fd, tmp, 1);
		if (byte != 1)
			break;
		if (tmp[0] != '\n')
			len++;
		else
			break;
	}
	return (len);
}

/*? 이게 맞는지 모르겠음 체크 필요함*/
/*맵의 세로 길이 체크하는 함수*/
int ft_check_width(int fd, int w_len)
{
	char	*tmp;
	int		len;
	int		byte;
	int		h_len;

	byte = 0;
	h_len = 1;
	while (1)
	{
		byte = read(fd, tmp, w_len);
		if (tmp = NULL)
			break;
		if (ft_strlen(tmp) < w_len || ft_strlen(tmp))
		{
			ft_printf("map width is wrong setting");
			free(tmp);
			return (0);
		}
		else
		{
			free(tmp);
			h_len++;
		}
	}
	return (h_len);
}
