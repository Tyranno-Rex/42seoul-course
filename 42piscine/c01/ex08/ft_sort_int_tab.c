/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:43:34 by eunjeong          #+#    #+#             */
/*   Updated: 2022/05/21 23:43:36 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	func_three(int *a, int n, int *box_total)
{
	int		i;

	i = 0;
	while (i < n)
	{
		a[i] = box_total[i];
		i++;
	}
}

void	func_setting(int *box_ten)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		box_ten[i] = 0;
		i++;
	}
}

void	func_two(int *a, int n, int the_num, int *box_total)
{
	int		box_ten[10];
	int		i;

	i = 0;
	func_setting(box_ten);
	while (i < n)
	{
		box_ten[a[i] / the_num % 10]++;
		i++;
	}
	i = 1;
	while (i < 10)
	{
		box_ten[i] += box_ten[i - 1];
		i++;
	}
	i = n - 1;
	while (i >= 0)
	{
		box_total[--box_ten[a[i] / the_num % 10]] = a[i];
		i--;
	}
	func_three(a, n, box_total);
}

void	func_one(int *a, int n, int the_max, int *box_total)
{
	int		the_num;

	the_num = 1;
	while (the_max / the_num > 0)
	{
		func_two(a, n, the_num, box_total);
		the_num *= 10;
	}
}

void	ft_sort_int_tab(int *a, int n)
{
	int		box_total[1000000];
	int		the_max;
	int		i;

	the_max = 0;
	i = 0;
	while (i < n)
	{
		if (a[i] > the_max)
			the_max = a[i];
		i++;
	}
	func_one(a, n, the_max, box_total);
}
