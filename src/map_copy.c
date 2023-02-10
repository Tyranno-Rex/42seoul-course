#include "./../include/so_long.h"

char	**ft_copymap(const char **map)
{
	char		**map_check;
	int			i;

	i = 0;
	map_check = malloc((ft_tab_size((const char **)map) + 1) * sizeof(char *));
	if (!map_check)
		ft_printf("Allocation of the check map failed!");
	while (map[i])
	{
		map_check[i] = ft_strdup(map[i]);
		if (!map_check[i])
			ft_printf("Allocation of the check map failed!");
		i++;
	}
	map_check[i] = NULL;
	return (map_check);
}