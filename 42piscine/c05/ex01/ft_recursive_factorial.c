/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:20:57 by eunjeong          #+#    #+#             */
/*   Updated: 2022/06/05 15:21:02 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	func_fac_iter(int the_num)
{
	if (the_num == 1 || the_num == 0)
		return (1);
	return (the_num * func_fac_iter(the_num - 1));
}

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	return (func_fac_iter(nb));
}
