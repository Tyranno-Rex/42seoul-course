/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:12:24 by marvin            #+#    #+#             */
/*   Updated: 2022/07/14 23:12:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s = src;
	char		*lasts;
	char		*lastd;

	d = dest;
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
	{
		*lasts = s + (n - 1);
		*lastd = d + (n - 1);
		while (n--)
		*lastd-- = *lasts--;
	}
	return (dest);
}
