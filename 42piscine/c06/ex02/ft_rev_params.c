/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:39:04 by eunjeong          #+#    #+#             */
/*   Updated: 2022/06/05 15:39:05 by eunjeong         ###   ########.fr       */
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

	i = ac - 1;
	while (i > 0)
	{
		av_len = func_av_len(av[i]);
		write(1, av[i], av_len);
		write(1, "\n", 1);
		i--;
	}
}
