/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:18:31 by eunjeong          #+#    #+#             */
/*   Updated: 2022/07/09 15:18:32 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *base1, const void *base2, size_t n)
{
    int i;
    unsigned char *s1;
    unsigned char *s2;

    i = 0;
    *s1 = (unsigned char*)base1;
    *s2 = (unsigned char*)base2;
    while (*s1 && *s2 && i < n)
    {
        if (*s1 > *s2 || *s1 < *s2)
            return (s1 - s2);
        *s1++;
        *s2++;
        i++;
    }
    return (0);
}
