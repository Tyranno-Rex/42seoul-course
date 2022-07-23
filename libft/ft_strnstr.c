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

// char	*ft_strnstr(const char *str, const char *to_find, size_t len)
// {
// 	size_t		flag;
// 	size_t		j;

// 	flag = 0;
// 	if (*to_find == '\0')
// 		return ((char *)str);
// 	while (str[++flag] != '\0' && flag < len)
// 	{
// 		j = 0;
// 		if (str[flag + j] == to_find[j] && flag + j < len)
// 		{	
// 			j++;
// 			if (to_find[j] == '\0')
// 				return ((char *)&str[flag]);
// 		}
// 		flag++;
// 	}
// 	return (0);
// }

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*to_find == '\0')
		return ((char *) str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] == to_find[j] && i + j < len)
		{
			j++;
			if (to_find[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
