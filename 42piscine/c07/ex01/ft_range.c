/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:19:43 by eunjeong          #+#    #+#             */
/*   Updated: 2022/06/06 17:19:44 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	long long	range;
	int			i;
	int			*arr;

	i = 0;
	range = max - min;
	if (range <= 0)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * range);
	if (!arr)
		return (0);
	while (i < range)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}
