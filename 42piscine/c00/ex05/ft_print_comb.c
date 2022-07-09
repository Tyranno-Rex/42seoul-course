/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.a[2]                                    :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:54:59 by eunjeong          #+#    #+#             */
/*   Updated: 2022/05/19 18:01:54 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	func_printer(char a[])
{
	char	c;
	char	d;

	if (a[0] == '7')
	{
		write(1, a, 3);
	}
	else
	{
		c = ',';
		d = ' ';
		write(1, a, 3);
		write(1, &c, 1);
		write(1, &d, 1);
	}
}

void	ft_print_comb(void)
{
	char	a[3];

	a[0] = '0';
	while (a[0] <= '7')
	{
		a[1] = a[0] + 1;
		while (a[1] <= '8')
		{
			a[2] = a[1] + 1;
			while (a[2] <= '9')
			{
				func_printer(a);
				a[2]++;
			}
			a[1]++;
		}
		a[0]++;
	}
}
