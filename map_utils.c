#include "so_long.h"

int	ft_count_collect(const char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_collect(t_data *g_data)
{
	g_data->nb_collec--;
	ft_printf("Move: %d\n", ++g_data->moves_counter);
	ft_printf("star collected!\n");
}

int	ft_search_tab(const char **tab, char c)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_tab_size(const char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

