/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:16:40 by eunjeong          #+#    #+#             */
/*   Updated: 2022/12/23 15:35:36 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_pf(size_t n)
{
	static int	i;
	char		*base;

	i = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putptr_pf(n / 16);
		n %= 16;
	}
	i += ft_putchar_pf(base[n]);
	return (i);
}

int	ft_pointer_pf(void *p)
{
	size_t	p_to_int;
	int		len;

	len = 0;
	p_to_int = (size_t)p;
	write(1, "0x", 2);
	len += ft_putptr_pf(p_to_int);
	return (len + 2);
}
