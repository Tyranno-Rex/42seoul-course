/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:55:03 by eunjeong          #+#    #+#             */
/*   Updated: 2022/12/23 03:19:08 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putint(long long n)
{
	static int	i;
	long long	nbr;

	nbr = n;
	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}				
	if (n > 9)
	{
		ft_putint(n / 10);
		n %= 10;
	}
	ft_putchar(n + '0');
	i++;
	if (nbr < 0)
		i++;
	return (i);
}
