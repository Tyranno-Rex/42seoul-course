/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:52:10 by eunjeong          #+#    #+#             */
/*   Updated: 2022/06/08 15:52:11 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

int	func_len(char *base)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*tmp;
	char	*tmp_to_tmp;

	i = 0;
	while (src[i])
		i++;
	tmp = malloc(sizeof(char) * i + 1);
	tmp_to_tmp = tmp;
	while (*src)
		*(tmp_to_tmp++) = *(src++);
	*tmp_to_tmp = '\0';
	return (tmp);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*arr;
	int			i;

	i = 0;
	arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!(arr))
		return (0);
	while (i < ac)
	{
		arr[i].str = av[i];
		arr[i].size = func_len(av[i]);
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[i].str = 0;
	return (arr);
}
