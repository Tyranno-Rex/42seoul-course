#include <unistd.h>

int main(int argc, char **argv)
{
	int			i;
	int			j;
	static int	str[256];

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j])
				{
					if (str[(int)argv[1][i]] == 0)
					{
						write(1, &argv[1][i], 1);
						str[(int)argv[1][i]] = 1;
					}
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// int	main(int ac, char *av[])
// {
// 	int			i;
// 	int			j;
// 	static int	tab[256];
    
// 	if (ac == 3)
// 	{
// 		i = 0;
// 		while (av[1][i])
// 		{
// 			j = 0;
// 			while (av[2][j])
// 			{
// 				if (av[1][i] == av[2][j])
// 				{
// 					if (tab[(int)av[1][i]] == 0)
// 					{
// 						write(1, &av[1][i], 1);
// 						tab[(int)av[1][i]] = 1;
// 					}
// 				}
// 				j++;
// 			}
// 			i++;
// 		}
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }