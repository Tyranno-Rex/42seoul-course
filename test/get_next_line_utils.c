/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:56:55 by eunjeong          #+#    #+#             */
/*   Updated: 2022/11/19 11:56:56 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	*new;
	int		i;

	if (!str || !c)
		return (NULL);
	i = 0;
	new = (char *)str;
	while (new[i])
	{
		if (new[i] == (char) c)
			return (&new[i]);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int base, size_t len)
{
	char			*result;
	unsigned int	len_s;
	size_t			i;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (base < len_s)
		result = malloc((sizeof(char) * len_s + 1));
	else if (base > len_s)
		result = malloc(sizeof(char));
	else
		result = malloc(len_s * sizeof(char) + 1);
	if (!result)
		return (NULL);
	i = 0;
	if ((base < len_s))
	{
		while ((i < len) && s[base])
			result[i++] = s[base++];
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*line;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	line = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!line)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		line[i] = s1[i];
		i++;
	}
	while (s2[j])
		line[i++] = s2[j++];
	line[i] = '\0';
	free(s1);
	return (line);
}
