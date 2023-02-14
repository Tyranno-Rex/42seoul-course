
#include "so_long.h"

static void	ft_check_begin_end(const char **map)
{
	int	i;
	int	tab_size;

	i = 0;
	tab_size = ft_tab_size(map) - 1;
	while (map[0][i] && map[tab_size][i])
	{
		if (map[0][i] != '1' || map[tab_size][i] != '1')
			ft_show_error("Map must be surrounded wall!");
		i++;
	}
	if (map[0][i] || map[tab_size][i])
	{
		ft_show_error("wrong map format!");
	}
}

static void	ft_map_closed(const char **map)
{
	int	i;
	int	j;
	int	len;
	int	tab_size;

	i = 0;
	len = ft_strlen(map[i]) - 1;
	tab_size = ft_tab_size(map) - 1;
	while (map[i])
	{
		j = 0;
		if (i == 0 || i == tab_size)
			ft_check_begin_end(map);
		else if (i != 0 && i != tab_size)
		{
			if (map[i][0] != '1' || map[i][len] != '1')
				ft_show_error("The map is not closed!");
		}
		i++;
	}
}

static void	ft_check_characters(const char **map, t_map *m_data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				m_data->character += 1;
			else if (map[i][j] == 'C')
				m_data->star += 1;
			else if (map[i][j] == 'E')
				m_data->exit += 1;
			else if (map[i][j] == '1' || map[i][j] == '0')
				m_data->wall += 1;
			else
				ft_show_error("The map contains an unknown character!");
			j++;
		}
		i++;
	}
	if (m_data->character < 1 || m_data->star < 1 || 
		m_data->exit < 1 || m_data->wall < 1)
		ft_show_error("One or some of the characters are missing!");
}

static void	ft_check_duplication(const char **map, t_map *m_data)
{
	int i = 0;
	if (map[1][1] == 'K')
		i++;
	if (m_data->character != 1 || m_data->exit != 1)
		ft_show_error("There's a duplication of characters!");
}

void	ft_map_validator(const char **map, t_map *t_data)
{
	ft_map_closed(map);
	ft_check_characters(map, t_data);
	ft_check_duplication(map, t_data);
}
