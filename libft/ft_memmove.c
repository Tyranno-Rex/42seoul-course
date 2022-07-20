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

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;

	if (dst == src || n == 0)
		return (dst);
	if (dst < src)
	{
		new_dst = (unsigned char *)dst;
		new_src = (unsigned char *)src;
		while (n--)
			*new_dst++ = *new_src++;
	}
	else
	{
		new_dst = (unsigned char *)dst + (n - 1);
		new_src = (unsigned char *)src + (n - 1);
		while (n--)
			*new_dst-- = *new_src--;
	}
	return (dst);
}
