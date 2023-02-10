#include "./../include/so_long.h"

char	**ft_copymap(const char **map)
{
	char		**copy_map;
	int			i;

	i = 0;
	copy_map = malloc((ft_map_height((const char **)map) + 1) * sizeof(char *));
	if (!copy_map)
	{
		ft_printf("Copy Map allocationi is failed!");
		exit(EXIT_FAILURE);
	}
	while (map[i])
	{
		copy_map[i] = ft_strdup(map[i]);
		if (!copy_map[i])
			ft_printf("Copy Map allocation is failed!");
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
}