/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:54:58 by eunjeong          #+#    #+#             */
/*   Updated: 2022/12/23 03:22:19 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstring(char *info)
{
	int	i;

	i = 0;
	if (!info)
	{
		ft_putstring("(null)");
		return (6);
	}
	while (info[i])
	{
		write(1, &info[i], 1);
		i++;
	}
	return (i);
}
