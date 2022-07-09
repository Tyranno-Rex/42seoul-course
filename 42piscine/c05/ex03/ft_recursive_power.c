/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:21:24 by eunjeong          #+#    #+#             */
/*   Updated: 2022/06/05 15:21:25 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	func_recursive_power(int the_num, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	return (the_num * func_recursive_power(the_num, power - 1));
}

int	ft_recursive_power(int nb, int power)
{
	return (func_recursive_power(nb, power));
}
