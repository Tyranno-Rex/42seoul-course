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

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    char *d = dest;
    const char *s = src;
    if (d < s)
    while (n--)
        *d++ = *s++;
    else
    {
        char *lasts = s + (n-1);
        char *lastd = d + (n-1);
        while (n--)
        *lastd-- = *lasts--;
    }
    return dest;
}