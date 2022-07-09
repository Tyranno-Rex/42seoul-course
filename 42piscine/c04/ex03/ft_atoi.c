/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:41:11 by eunjeong          #+#    #+#             */
/*   Updated: 2022/05/26 19:31:32 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	func_check(char *c, int the_result_plus, int i, long the_result)
{
	int		j;

	j = 0;
	while (c[i] == '\r' || c[i] == '\v' || c[i] == '\t' || c[i] == '\n' \
		|| c[i] == 32 || c[i] == '\f')
		i++;
	while (c[i] == '-' || c[i] == '+')
	{	
		if (c[i] == '-')
			the_result_plus *= -1;
		i++;
	}
	if ((c[i] >= '0') && (c[i] <= '9'))
	{
		while ((c[i] >= '0') && (c[i] <= '9'))
		{
			the_result = ((the_result * 10) + (c[i] - '0'));
			i++;
		}
		return (the_result * the_result_plus);
	}
	else
		return (0);
	i++;
	return (0);
}

int	ft_atoi(char *the_char)
{
	int		i;

	i = func_check(the_char, 1, 0, 0);
	return (i);
}
