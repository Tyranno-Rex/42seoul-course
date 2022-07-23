/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:04:44 by marvin            #+#    #+#             */
/*   Updated: 2022/07/09 19:04:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strrchr(const char *str, int c)
// {
// 	int		len;

// 	len = ft_strlen(str);
// 	while (len >= 0)
// 	{
// 		if (str[len] == c)
// 			break ;
// 		len--;
// 		str++;
// 	}
// 	if (len >= 0)
// 		return ((char *)str);
// 	return (NULL);
// }

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}
