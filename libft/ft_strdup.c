/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:19:10 by eunjeong          #+#    #+#             */
/*   Updated: 2022/07/09 15:19:12 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*p;
	size_t	slen;
	size_t	index;

	index = 0;
	slen = ft_strlen(src);
	p = (char *)malloc(sizeof(char) * (slen + 1));
	if (!p)
		return (0);
	while (index < slen)
	{
		p[index] = src[index];
		index++;
	}
	p[index] = '\0';
	return (p);
}
