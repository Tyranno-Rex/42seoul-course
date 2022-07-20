/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:52:50 by eunjeong          #+#    #+#             */
/*   Updated: 2022/07/09 14:52:52 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	func_check(char *c, int the_result_plus, int i, long the_result)
{
	int		j;

	j = 0;
	while (c[i] == '\r' || c[i] == '\v' || c[i] == '\t' || c[i] == '\n' \
		|| c[i] == 32 || c[i] == '\f')
		i++;
	if (c[i] == '-' || c[i] == '+')
	{
		if (c[i] == '-')
			the_result_plus *= -1;
		i++;
	}
	while ((c[i] >= '0') && (c[i] <= '9'))
	{
		if (the_result * the_result_plus > 2147483647)
			return (-1);
		else if (the_result * the_result_plus < -2147483648)
			return (0);
		the_result = ((the_result * 10) + (c[i] - '0'));
		i++;
	}
	return (the_result * the_result_plus);
}

int	ft_atoi(char *the_char)
{
	int		i;

	i = func_check(the_char, 1, 0, 0);
	return (i);
}
