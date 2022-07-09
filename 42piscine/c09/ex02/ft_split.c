/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:18:21 by eunjeong          #+#    #+#             */
/*   Updated: 2022/06/08 16:18:23 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	func_check_valid(char c, char *charset)
{
	int		i;

	i = -1;
	while (charset[++i])
	{
		if (charset[i] == c)
			return (0);
	}
	return (1);
}

int	func_size_height(char *str, char *charset)
{
	int		num;
	int		i;

	i = 0;
	num = 0;
	while (str[i])
	{
		while (str[i] && !func_check_valid(str[i], charset))
			i++;
		if (str[i] && func_check_valid(str[i], charset))
		{
			num++;
			while (str[i] && func_check_valid(str[i], charset))
				i++;
		}
	}
	return (num);
}

char	*func_insert(char *str, char *charset)
{
	int		i;
	int		num;
	char	*the_char;

	num = -1;
	while (str[++num] && func_check_valid(str[num], charset))
	the_char = (char *)malloc(sizeof(char) * (num) + 1);
	i = -1;
	while (str[++i] && func_check_valid(str[i], charset))
		the_char[i] = str[i];
	the_char[i] = 0;
	return (the_char);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**the_arr;

	i = 0;
	the_arr = (char **)malloc(sizeof(char *) * \
	(func_size_height(str, charset)) + 1);
	while (*str)
	{
		while (*str && !func_check_valid(*str, charset))
			str++;
		if (*str && func_check_valid(*str, charset))
		{
			the_arr[i] = func_insert(str, charset);
			i++;
			while (*str && func_check_valid(*str, charset))
				str++;
		}
	}
	the_arr[i] = 0;
	return (the_arr);
}
