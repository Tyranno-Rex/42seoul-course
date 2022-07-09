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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*tmp;
	unsigned int	i;
	unsigned int	j;

	tmp = malloc(sizeof(char) * (len - start) + 1);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && i <= len -1)
		{
			tmp[j] = s[i];
			j++;
		}
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}
