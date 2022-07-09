/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:20:15 by eunjeong          #+#    #+#             */
/*   Updated: 2022/05/19 21:20:18 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr(int the_num);
void	func_printer(int the_num);
void	func_cal(int the_num);

void	func_printer(int the_num)
{
	char		the_char;

	the_char = the_num + '0';
	write(1, &the_char, 1);
}

void	func_cal(int the_num)
{
	int		a;

	if (the_num > 9)
	{
		a = the_num % 10;
		the_num = the_num / 10;
		ft_putnbr(the_num);
		func_printer(a);
	}
	else
		func_printer(the_num);
}

void	ft_putnbr(int the_num)
{
	if (the_num >= 0)
	{
		func_cal(&the_num);
	}
	else if (the_num < 0)
	{
		if (the_num == -2147483648)
			write(1, "-2147483648", 11);
		else
		{
			write(1, "-", 1);
			func_cal(-the_num);
		}
	}
}
