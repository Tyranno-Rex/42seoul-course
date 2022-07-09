/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:16:26 by eunjeong          #+#    #+#             */
/*   Updated: 2022/06/06 17:20:23 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*func_str_to_base_two(int nbr, char *base, char *dest, int index);

int	func_base_len(char *base)
{
	int		i;
	int		j;

	i = -1;
	if (base[0] == '\0')
		return (-1);
	while (base[++i])
	{
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-' \
		|| base[i] == '\r' || base[i] == '\t' || base[i] == '\n' \
		|| base[i] == '\f' || base[i] > 127)
			return (-1);
		j = i;
		while (base[++j])
		{
			if (base[i] == base[j])
				return (-1);
		}
	}
	if (i <= 1)
		return (-1);
	else
		return (i);
}

int	func_str_cal(char c, char *base)
{
	int		i;

	i = -1;
	while (base[++i] != '\0')
	{
		if (c == base[i])
			return (i);
	}
	return (-1);
}

int	func_str_to_base(char *s, char *b, int i)
{
	int			plus;
	int			one;
	long long	result;
	int			base_len;

	result = 0;
	plus = 1;
	base_len = func_base_len(b);
	if (func_base_len(b) == -1)
		return (0);
	while (s[i] == '\r' || s[i] == '\v' || s[i] == '\t' || s[i] == '\n' \
		|| s[i] == 32 || s[i] == '\f')
		i++;
	while (s[i] == '-' || s[i] == '+')
	{	
		if (s[i] == '-')
			plus *= -1;
		i++;
	}
	while (func_str_cal(s[i], b) != -1)
	{
		result = ((result * base_len) + (one = func_str_cal(s[i], b)));
		i++;
	}
	return (result * plus);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		the_num;
	int		index;
	char	*the_result;

	index = 0;
	if (func_base_len(base_from) == -1 || (func_base_len(base_to)) == -1)
		return (NULL);
	the_num = func_str_to_base(nbr, base_from, 0);
	the_result = (char *)malloc(sizeof(char) * 40);
	func_str_to_base_two(the_num, base_to, the_result, index);
	return (the_result);
}
