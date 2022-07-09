/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:38:36 by eunjeong          #+#    #+#             */
/*   Updated: 2022/06/05 15:38:38 by eunjeong         ###   ########.fr       */
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
	int		i;
	int		av_len;

	i = 1;
	while (i < ac)
	{
		av_len = func_av_len(av[i]);
		write(1, av[i], av_len);
		write(1, "\n", 1);
		i++;
	}
}
