/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:03:22 by eunjeong          #+#    #+#             */
/*   Updated: 2022/11/19 16:43:29 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_pro(const char *s, char c)
{
	size_t	i;

	i = 0;
	if (c == '\0' && s)
	{
		while (s[i])
			i++;
	}
	else if (c == '\n' && s)
	{
		while (s[i] && s[i] != '\n')
			i++;
	}
	return (i);
}

static char	*ft_save_line_and_return(char **str)
{
	char	*line;
	char	*ptr;

	ptr = *str;
	while (*ptr && *ptr != '\n')
		ptr++;
	ptr += (*ptr == '\n');
	line = ft_substr_gnl (*str, 0, (size_t)(ptr - *str));
	if (!line)
	{
		free (*str);
		return (0);
	}
	ptr = ft_substr_gnl (ptr, 0, ft_strlen_gnl (ptr));
	free (*str);
	*str = ptr;
	return (line);
}

char	*ft_read_and_add(char *temp, int fd, char *buf)
{
	int		check_byte;

	check_byte = 1;
	while (check_byte && !ft_strchr_gnl (temp, '\n'))
	{
		check_byte = read (fd, buf, BUFFER_SIZE);
		if (check_byte == -1)
		{
			free (buf);
			free (temp);
			return (0);
		}
		buf[check_byte] = 0;
		temp = ft_strjoin_gnl(temp, buf);
	}
	free (buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*static_char[10000];
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!static_char[fd])
		static_char[fd] = ft_strdup_gnl("");
	temp = malloc (sizeof (*temp) * (BUFFER_SIZE + 1));
	if (!temp)
	{
		free (static_char[fd]);
		return (0);
	}
	static_char[fd] = ft_read_and_add(static_char[fd], fd, temp);
	if (!static_char[fd])
		return (0);
	if (!*static_char[fd])
	{
		free (static_char[fd]);
		static_char[fd] = 0;
		return (0);
	}
	return (ft_save_line_and_return(&static_char[fd]));
}
