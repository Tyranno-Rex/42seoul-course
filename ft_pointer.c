/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:16:40 by eunjeong          #+#    #+#             */
/*   Updated: 2022/12/23 03:22:06 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned int n)
{
	static int	i;
	char		*base;

	i = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putptr(n / 16);
		n %= 16;
	}
	i++;
	ft_putchar(base[n]);
	return (i);
}

int	ft_pointer(void *p)
{
	unsigned int	p_to_int;
	int				len;

	len = 0;
	p_to_int = (unsigned int)p;
	write(1, "0x", 2);
	len = ft_putptr(p_to_int);
	return (len + 2);
}
