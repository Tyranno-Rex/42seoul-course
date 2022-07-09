/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:53:47 by eunjeong          #+#    #+#             */
/*   Updated: 2022/06/08 15:53:48 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putnbr(int the_num);
void	func_cal(int the_num);

void	put_str(char *str)
{
	char	a;
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{
		a = str[i];
		write(1, &a, 1);
	}
	write(1, "\n", 1);
}

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
		func_cal(the_num);
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

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str != 0)
	{
		put_str(par->str);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		put_str(par->copy);
		par++;
	}
}
