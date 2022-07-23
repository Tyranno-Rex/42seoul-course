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
	char	*ret;
	size_t	i;
	size_t	len;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	ret = (char *)malloc(len + 1);
	if (ret == 0)
		return (0);
	*(ret + len) = 0;
	i = 0;
	while (i < len)
	{
		*(ret + i) = f(i, *(s + i));
		i++;
	}
	return (ret);
}
