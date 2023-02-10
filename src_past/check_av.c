#include "./../include/so_long.h"


// ac의 개수와 .ber 형식을 맞췄는지 확인
void ft_check_av(int ac, char **av)
{
	if (ac != 2 || ft_strnstr(av[1], ".ber",ft_strlen(av[1]) == 0))
	{
		if (ac != 2)
			ft_printf("ac must be two, your ac isn't two");
		else
			ft_printf("your map format must be \".ber\"");
		exit(EXIT_FAILURE);
	}
}


