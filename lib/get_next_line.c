/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:54:49 by eunjeong          #+#    #+#             */
/*   Updated: 2022/11/19 11:54:52 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_return_str(char *buf)
{
	char	*result;
	int		i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	result = ft_gnl_substr(buf, 0, i);
	if (!result)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

char	*ft_gnl_update_str(char *buf)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	result = malloc(sizeof(char) * (ft_gnl_strlen(buf) - i + 1));
	if (!result)
	{
		free(result);
		return (NULL);
	}
	i++;
	j = 0;
	while (buf[i])
		result[j++] = buf[i++];
	result[j] = '\0';
	free(buf);
	return (result);
}

char	*ft_gnl_read_str(int fd, char *buf)
{
	int		check_byte;
	char	*temp;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	check_byte = 1;
	while (!ft_gnl_strchr(buf, '\n') && check_byte != 0)
	{
		check_byte = read(fd, temp, BUFFER_SIZE);
		if (check_byte < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[check_byte] = '\0';
		buf = ft_gnl_strjoin(buf, temp);
	}
	free(temp);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*static_str;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	static_str = ft_gnl_read_str(fd, static_str);
	if (!static_str)
		return (NULL);
	result = ft_gnl_return_str(static_str);
	static_str = ft_gnl_update_str(static_str);
	return (result);
}
