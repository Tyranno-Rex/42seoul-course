/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:16:48 by eunjeong          #+#    #+#             */
/*   Updated: 2022/06/06 17:20:29 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	func_base_len(char *base);

void	func_cal_index(long long num, int base_len, int *index)
{
	while (num > 0)
	{
		num /= base_len;
		(*index)++;
	}
}

void	func_setting(long long *num, int *i1, int *i2, int *total)
{
	(*num) *= -1;
	(*i1) += 1;
	(*i2) += 1;
	(*total) += 1;
}

void	func_setting_2(int *i1, int *i2, int *i3, int index)
{
	(*i1) = 0;
	(*i2) = 0;
	(*i3) = index;
}

char	*func_str_to_base_two(int nbr, char *base, char *dest, int index)
{
	int				i[5];
	long long		num;

	func_setting_2(&i[0], &i[1], &i[4], index);
	num = nbr;
	if (num == 0)
	{
		dest[0] = base[0];
		dest[1] = 0;
		return (&base[0]);
	}
	if (num < 0)
	{
		func_setting(&num, &i[0], &i[1], &i[4]);
		dest[0] = '-';
	}
	func_cal_index(num, (i[3] = func_base_len(base)), &i[4]);
	while (--i[4] >= i[0])
	{
		dest[i[4]] = base[num % i[3]];
		num /= i[3];
		i[1]++;
	}
	dest[i[1]] = '\0';
	return (dest);
}
