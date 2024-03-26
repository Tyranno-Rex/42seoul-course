/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:38:52 by eunjeong          #+#    #+#             */
/*   Updated: 2023/03/31 14:10:20 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*ft_choose_xy(const char **map)
{
	int			x;
	int			y;
	int			*xy;

	y = 0;
	xy = (int *)ft_calloc(2, sizeof(int));
	if (!xy)
		ft_show_error("allocation failed!");
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				xy[0] = x;
				xy[1] = y;
				break ;
			}
			x++;
		}
		y++;
	}
	return (xy);
}

char	**ft_copymap(const char **map)
{
	char		**map_check;
	int			i;

	i = 0;
	map_check = malloc((ft_tab_size((const char **)map) + 1) * sizeof(char *));
	if (!map_check)
		ft_show_error("allcation failed!");
	while (map[i])
	{
		map_check[i] = ft_strdup(map[i]);
		if (!map_check[i])
			ft_show_error("allcation failed!");
		i++;
	}
	map_check[i] = NULL;
	return (map_check);
}

void	ft_flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || x >= (int)ft_strlen_pro(map[0], '\n')
		|| y >= ft_tab_size((const char **)map) || map[y][x] == '1'
		|| map[y][x] == 'V' || map[y][x] == 'E')
		return ;
	if (map[y][x] != 'P')
		map[y][x] = 'V';
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x, y - 1);
	ft_flood_fill(map, x, y + 1);
}

void	ft_check_validpath(const char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				ft_show_error("map can't clear!");
			if (map[i][j] == 'E' && map[i - 1][j] != 'V' && map[i + 1][j] != 'V'
			&& map[i][j - 1] != 'V' && map[i][j + 1] != 'V')
				ft_show_error("map can't clear!");
			j++;
		}
		i++;
	}
}
