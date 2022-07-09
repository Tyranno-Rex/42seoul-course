/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:29:40 by eunjeong          #+#    #+#             */
/*   Updated: 2022/06/08 20:29:42 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int		*recevier;
	int		i;

	i = -1;
	while (tab[++i])
	recevier = (int *)malloc(sizeof(int) * i);
	i = -1;
	while (tab[++i])
		recevier = f(tab[i]);
	return (recevier);
}
