/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:02:28 by eunjeong          #+#    #+#             */
/*   Updated: 2022/05/27 10:09:14 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	func_base_len(char *base)
{
	int		i;
	int		j;

	i = -1;
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

int	func_check_str(char c, char *base)
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

int	func_str_to_base(char *s, char *b, int i, int len_base)
{
	int		plus;
	int		one;
	long	result;

	result = 0;
	plus = 1;
	while (s[i] == '\r' || s[i] == '\v' || s[i] == '\t' || s[i] == '\n' \
		|| s[i] == 32 || s[i] == '\f')
		i++;
	while (s[i] == '-' || s[i] == '+')
	{	
		if (s[i] == '-')
			plus *= -1;
		i++;
	}
	if (func_check_str(s[i], b) != -1)
	{
		while (func_check_str(s[i], b) != -1)
		{
			result = ((result * len_base) + (one = func_check_str(s[i], b)));
			i++;
		}
		return (result * plus);
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int		len_base;
	int		result;

	if ((func_base_len(base)) == -1)
		return (0);
	len_base = func_base_len(base);
	result = func_str_to_base(str, base, 0, len_base);
	return (result);
}
