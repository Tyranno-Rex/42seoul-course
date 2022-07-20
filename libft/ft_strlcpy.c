/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:04:20 by marvin            #+#    #+#             */
/*   Updated: 2022/07/09 19:04:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	func_len(char *the_char)
{
	int		i;

	i = 0;
	while (the_char[i] != 0)
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = func_len(src);
	if (size == 0)
		return (j);
	while (src[i] != '\0' && i < size)
	{
		if (i == size - 1)
		{
			dest[i] = '\0';
			return (j);
		}
		dest[i] = src[i];
		i++;
	}
	return (j);
}
