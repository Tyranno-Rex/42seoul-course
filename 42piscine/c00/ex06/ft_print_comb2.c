/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_com2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:21:49 by eunjeong          #+#    #+#             */
/*   Updated: 2022/05/19 21:20:42 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	func_write(int a[])
{
	char	the_a[2];
	char	the_b[2];
	char	the_c;
	char	the_d;

	the_a[0] = a[0] / 10 + '0';
	the_a[1] = a[0] % 10 + '0';
	the_b[0] = a[1] / 10 + '0';
	the_b[1] = a[1] % 10 + '0';
	the_c = ',';
	the_d = ' ';
	write(1, &the_a[0], 1);
	write(1, &the_a[1], 1);
	write(1, &the_d, 1);
	write(1, &the_b[0], 1);
	write(1, &the_b[1], 1);
	write(1, &the_c, 1);
	write(1, &the_d, 1);
}

void	func_except(void)
{
	char	a[5];

	a[0] = '9';
	a[1] = '8';
	a[2] = ' ';
	a[3] = '9';
	a[4] = '9';
	write(1, a, 5);
}

void	ft_print_comb2(void)
{
	int	a[2];

	a[0] = 0;
	while (a[0] <= 98)
	{
		a[1] = a[0] + 1;
		while (a[1] <= 99)
		{
			if (a[0] == 98 && a[1] == 99)
				func_except();
			else
				func_write(a);
			a[1]++;
		}
		a[0]++;
	}
}
