#include <unistd.h>

int	main(int ac, char*av[])
{
	int			i;
	int			j;
	static int	tab[256];

	if (ac == 3)
	{
		j = 1;
		while (j <= 2)
		{
			i = 0;
			while (av[j][i])
			{
				if (tab[(int)av[j][i]] == 0)
				{
					write(1, &av[j][i], 1);
					tab[(int)av[j][i]] = 1;
				}
				i++;
			}
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}