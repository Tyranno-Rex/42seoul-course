/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:48:45 by eunjeong          #+#    #+#             */
/*   Updated: 2022/08/12 16:59:58 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char	*buf;
	char	*tmp;
	char	*save[OPEN_MAX];
	ssize_t	offset;
	ssize_t	index;

	if (fd < 0 || fd > OPEN_MAX || line == NULL || BUFFER_SIZE <= 0)
		return (FT_FAIL);
	if ((buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))) == 0)
		return (FT_FAIL);
	while ((index = find_newline(save[fd])) == FT_FAIL && (offset = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		
	}
	
}
