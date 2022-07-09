/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 21:21:45 by eunjeong          #+#    #+#             */
/*   Updated: 2022/05/27 10:02:01 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	func_printer(char c)
{
	write(1, &c, 1);
}

void	func_make(long the_num, char *the_string, int i)
{
	char	the_char1;

	if (the_num >= i)
	{
		the_char1 = the_string[the_num % i];
		func_make(the_num / i, the_string, i);
		func_printer(the_char1);
	}
	else
		func_printer(the_string[the_num % i]);
}

int	func_len(char *base)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i[3];
	long	the_num;

	i[0] = func_len(base);
	i[1] = -1;
	while (++i[1] < i[0])
	{
		i[2] = i[1];
		while (++i[2] <= i[0])
		{
			if ((base[i[1]] == base[i[2]]) || base[i[1]] == '+' \
			|| base[i[1]] == '-')
				return ;
		}
	}
	if (i[0] == 0 || i[0] == 1)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		the_num = nbr;
		func_make(-the_num, base, i[0]);
	}
	else
		func_make(nbr, base, i[0]);
}
