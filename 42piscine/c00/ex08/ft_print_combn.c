/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:22:03 by eunjeong          #+#    #+#             */
/*   Updated: 2022/05/23 22:22:07 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	func_check(int *arr, int the_case)
{
	int		i[2];

	i[1] = 0;
	i[0] = the_case - 1;
	while (i[0] > 0)
	{
		if (arr[i[0]] > 10 - the_case + i[0])
			arr[i[0] - 1] += 1;
		i[0] -= 1;
	}
	i[0] = 1;
	while (i[0] < the_case)
	{
		if (arr[i[0]] > 10 - the_case + i[0])
			arr[i[0]] = arr[i[0] - 1] + 1;
		i[0] += 1;
	}
}

void	func_printer(int arr[], int the_case, int the_total, int the_num)
{
	int		i;
	char	c;

	i = 0;
	while (i < the_case)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		i++;
	}
	if (the_total == the_num - 1)
		return ;
	else
		write(1, ", ", 2);
}

void	func_setting(int the_num, int the_case)
{
	int		arr[100];
	int		i;

	i = 0;
	while (i < the_case)
	{
		arr[i] = i;
		i++;
	}
	i = 0;
	while (i < the_num)
	{
		func_check(arr, the_case);
		func_printer(arr, the_case, i, the_num);
		arr[the_case - 1] += 1;
		i++;
	}
}

int	func_combi(int n)
{
	int		the_p;
	int		the_n;
	int		the_c;

	the_p = 1;
	the_n = 1;
	the_c = 1;
	while (the_n <= n)
	{
		the_p *= (10 - the_n + 1);
		the_c *= the_n;
		the_n++;
	}
	the_p = the_p / the_c;
	return (the_p);
}

void	ft_print_combn(int n)
{
	int		total;

	total = func_combi(n);
	func_setting(total, n);
}
