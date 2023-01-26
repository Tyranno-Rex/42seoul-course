/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:19:18 by eunjeong          #+#    #+#             */
/*   Updated: 2023/01/27 03:19:20 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_signal_write(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0b1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("SERVER PID = %d\n\n", pid);
	signal(SIGUSR1, ft_signal_write);
	signal(SIGUSR2, ft_signal_write);
	while (1)
		pause();
}
