/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:20:05 by eunjeong          #+#    #+#             */
/*   Updated: 2022/06/06 17:20:06 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	func_len(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	func_zero(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

int	func_size(char **strs, char *sep, int size)
{
	int		i;
	int		result;

	i = -1;
	result = 0;
	while (++i < size)
		result += func_len(strs[i]);
	result += (func_len(sep)) * (size - 1);
	return (result);
}	

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i[4];
	char	*join;

	if (size == 0)
	{
		join = (char *)malloc(sizeof(char) * 1);
		join[0] = '\0';
		return (join);
	}
	i[3] = func_size(strs, sep, size);
	join = (char *)malloc(sizeof(char) * i[3] + 1);
	func_zero(&i[3], &i[0], &i[1]);
	while (i[3] < size)
	{
		i[2] = 0;
		while (strs[i[1]][i[2]])
			join[i[0]++] = strs[i[1]][i[2]++];
		i[2] = 0;
		while (sep[i[2]] && i[3] < (size - 1))
			join[i[0]++] = sep[i[2]++];
		i[1]++;
		i[3]++;
	}
	join[i[0]] = 0;
	return (join);
}
