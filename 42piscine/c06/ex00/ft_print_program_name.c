/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:38:19 by eunjeong          #+#    #+#             */
/*   Updated: 2022/06/05 15:38:20 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	func_av_len(char *av)
{
	int		i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int		len_av;

	if (ac == 1)
	{
		len_av = func_av_len(av[0]);
		write(1, av[0], len_av);
		write(1, "\n", 1);
		return (0);
	}
	return (0);
}
