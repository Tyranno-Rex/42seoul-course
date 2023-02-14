/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:17:43 by eunjeong          #+#    #+#             */
/*   Updated: 2022/12/23 03:22:15 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_pf(unsigned int nbr, char *b)
{
	static int	i;

	i = 0;
	if (nbr >= ft_strlen_pf(b))
	{
		ft_puthex_pf(nbr / ft_strlen_pf(b), b);
		nbr = nbr % ft_strlen_pf(b);
	}
	i += 1;
	ft_putchar_pf(b[nbr]);
	return (i);
}
