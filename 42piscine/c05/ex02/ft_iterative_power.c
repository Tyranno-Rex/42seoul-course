/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:21:14 by eunjeong          #+#    #+#             */
/*   Updated: 2022/06/05 15:21:16 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	func_iter_power(int nb, int power)
{
	int		i;
	int		result;

	i = -1;
	result = 1;
	while (++i < power)
		result *= nb;
	return (result);
}

int	ft_iterative_power(int nb, int power)
{
	int		i;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = func_iter_power(nb, power);
	return (i);
}
