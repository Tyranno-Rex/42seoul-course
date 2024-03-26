/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:10:45 by eunjeong          #+#    #+#             */
/*   Updated: 2022/11/19 16:43:50 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*line;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	line = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (line == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			line[i] = left_str[i];
	while (buff[j] != '\0')
		line[i++] = buff[j++];
	line[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (line);
}

char *ft_line(char *line)
{
    int i;
    char *tab;
    
    i = 0;
    if (!line[i])
        return (NULL);
    while (line[i] && line[i] != '\n')
        i++;
    tab = (char *)malloc(sizeof(char) * (i + 2));
    if(!tab)
        return (NULL);
    i = 0;
    while (line[i] && line[i] != '\n')
    {
        tab[i] = line[i];
        i++;
    }
    if (line[i] == '\n')
    {
        tab[i] = line[i];
        i++;
    }
    tab[i] = '\0';
    return (tab);
}

char *ft_next_str(char *line)
{
    int i;
    int j;
    char *tab;

    i = 0;
    while (line[i] && line[i] != '\n')
        i++;
    if (!line[i])
    {
        free(line);
        return (NULL);
    }
    tab = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
    if (!tab)
        return (NULL);
    i++;
    j = 0;
    while (line[i])
        tab[j++] = line[i++];
    tab[j] = '\0';
    free(line);
    return (tab);
}