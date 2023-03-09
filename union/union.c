#include <unistd.h>


int main(int argc, char **argv)
{
	int 		i;
	int 		j;
	static int 	str[256];
	
	if (argc == 3)
	{
		i = 1;
		while (i <= 2)
		{
			j = 0;
			while (argv[i][j])
			{
				if (str[(int)argv[i][j]] == 0)
				{
					write(1, &argv[i][j], 1);
					str[(int)argv[i][j]] = 1;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}


// int	main(int ac, char*av[])
// {
// 	int			i;
// 	int			j;
// 	static int	tab[256];

// 	if (ac == 3)
// 	{
// 		j = 1;
// 		while (j <= 2)
// 		{
// 			i = 0;
// 			while (av[j][i])
// 			{
// 				if (tab[(int)av[j][i]] == 0)
// 				{
// 					write(1, &av[j][i], 1);
// 					tab[(int)av[j][i]] = 1;
// 				}
// 				i++;
// 			}
// 			j++;
// 		}
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }