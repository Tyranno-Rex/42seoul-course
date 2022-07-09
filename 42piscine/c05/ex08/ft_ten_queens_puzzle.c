/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:22:26 by eunjeong          #+#    #+#             */
/*   Updated: 2022/06/05 15:22:28 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	func_printer(int *arr)
{
	int		the_num;
	char	the_char;

	the_num = 0;
	while (the_num < 10)
	{
		the_char = arr[the_num] + '0';
		write(1, &the_char, 1);
		the_num++;
	}
	write(1, "\n", 1);
}

int	func_vaild(int *the_arr, int i)
{
	int		the_num;
	int		arr_abs;

	the_num = 0;
	while (the_num < i)
	{
		if (the_arr[i] > the_arr[the_num])
			arr_abs = the_arr[i] - the_arr[the_num];
		else
			arr_abs = the_arr[the_num] - the_arr[i];


		if (the_arr[i] == the_arr[the_num] || arr_abs == (i - the_num))
			return (0);
		the_num++;
	}
	return (1);
}

void	func_backtracing(int *the_arr, int i, int *cnt)
{
	int		the_num;

	the_num = 0;
	if (i == 9)
	{
		(*cnt)++;
		func_printer(the_arr);
	}
	while (the_num < 10)
	{
		the_arr[i + 1] = the_num;
		if (func_vaild(the_arr, i + 1))
			func_backtracing(the_arr, i + 1, cnt);
		the_num++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		the_arr[11];
	int		cnt;
	int		i;

	i = -1;
	cnt = 0;
	while (++i < 10)
		the_arr[i] = -1;
	func_backtracing(the_arr, -1, &cnt);
	return (cnt);
}
