/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:03:24 by marvin            #+#    #+#             */
/*   Updated: 2022/07/15 20:03:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*str;
	unsigned int	index;

	index = 0;
	str = NULL;
	len = (unsigned int)(ft_strlen(s));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (index < len)
	{
		str[index] = f(index, s[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}
