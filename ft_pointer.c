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

int	ft_pointer(void *p)
{
	size_t	nbr;

	nbr = (size_t)p;
	write(1, "0x", 2);
	return (ft_putptr(nbr) + 2);
}

int	ft_putptr(size_t nbr)
{
	char		*base;
	static int	i;

	i = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_putptr(nbr / 16);
		nbr = nbr % 16;
	}
	i++;
	ft_putchar(base[nbr]);
	return (i);
}
