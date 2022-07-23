/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:04:47 by marvin            #+#    #+#             */
/*   Updated: 2022/07/09 19:04:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*str;
// 	size_t	i;

// 	i = 0;
// 	if (s == 0)
// 		return (NULL);
// 	if (start >= ft_strlen(s))
// 	{
// 		str = malloc(1);
// 		if (!str)
// 			return (0);
// 		str[0] = '\0';
// 		return (str);
// 	}
// 	str = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!str)
// 		return (NULL);
// 	while (s[i] && i < len)
// 		str[i++] = s[start++];
// 	str[i] = 0;
// 	return (str);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
	{
		len = ft_strlen(s);
		tmp = (char *)malloc(len - start + 1);
	}
	else
		tmp = (char *)malloc(len + 1);
	if (!tmp)
		return (0);
	*(tmp + len) = 0;
	i = 0;
	while (i < len && *(s + start + i))
	{
		*(tmp + i) = *(s + start + i);
		i++;
	}
	return (tmp);
}
