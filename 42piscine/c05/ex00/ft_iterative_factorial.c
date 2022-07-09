/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:57:13 by eunjeong          #+#    #+#             */
/*   Updated: 2022/06/05 15:20:45 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	func_iter_fac(int the_num)
{
	int		the_result;

	the_result = 1;
	while (the_num > 1)
	{
		the_result = the_result * the_num;
		the_num--;
	}
	return (the_result);
}

int	ft_iterative_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	return (func_iter_fac(nb));
}
