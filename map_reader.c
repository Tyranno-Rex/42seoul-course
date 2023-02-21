/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:38:57 by eunjeong          #+#    #+#             */
/*   Updated: 2023/02/18 12:38:58 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static char	*ft_static_strjoin(char *s1, char *s2)
{
	char	*result;

	if (!s1)
		s1 = ft_strdup("");
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

char	**ft_read_map(const char *path)
{
	int		fd;
	char	*line;
	char	*map_content;
	char	**map_tab;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL || *line == '\n')
	{
		ft_show_error("The map isn't in shape!");
	}
	map_content = NULL;
	while (line != NULL)
	{
		map_content = ft_static_strjoin(map_content, line);
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	map_tab = ft_split(map_content, '\n');
	free(map_content);
	close(fd);
	return (map_tab);
}
