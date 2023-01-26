/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:09:21 by eunjeong          #+#    #+#             */
/*   Updated: 2023/01/27 03:19:52 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_string_is_num(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (!ft_isdigit(c[i]))
		{
			ft_printf("pid must consist of numbers only");
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_CtoS(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0b1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	check_digit;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i] != '\0')
		{
			ft_CtoS(pid, av[2][i]);
			i++;
		}
		ft_CtoS(pid, '\n');
	}
	else
	{
		ft_printf("The number of arguments for client must be 3.");
		return (1);
	}
	check_digit = ft_string_is_num(av[1]);
	if (check_digit == 1)
		return (0);
	return (0);
}
