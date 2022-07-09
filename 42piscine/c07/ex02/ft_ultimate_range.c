/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:19:52 by eunjeong          #+#    #+#             */
/*   Updated: 2022/06/06 17:19:57 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int			i;
	long long	num;

	i = 0;
	num = max - min;
	if (max <= min)
	{
		(*range) = 0;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * (num));
	if (!(*range))
		return (-1);
	while (min < max)
	{
		(*range)[i++] = min++;
	}
	return (i);
}
