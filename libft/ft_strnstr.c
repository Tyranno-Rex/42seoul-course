/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:04:40 by marvin            #+#    #+#             */
/*   Updated: 2022/07/09 19:04:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	int		i;
	size_t	flag;
	int		len_find;

	len_find = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (to_find[len_find] != '\0')
		len_find++;
	flag = -1;
	while (str[++flag] != '\0' && flag < len)
	{
		if (str[flag] == to_find[0])
		{	
			i = 0;
			while (str[flag + i] == to_find[i] && i < len_find)
				i++;
			if (to_find[i] == '\0')
				return (&str[flag]);
		}
	}
	return (0);
}
