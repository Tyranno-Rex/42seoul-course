/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:38:55 by eunjeong          #+#    #+#             */
/*   Updated: 2022/06/05 15:38:57 by eunjeong         ###   ########.fr       */
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

int	func_if_change(char *av1, char *av2)
{
	int		i;

	i = 0;
	while (av1[i] != '\0' && av2[i] != '\0' && av1[i] == av2[i])
		i++;
	return (av1[i] - av2[i]);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = ac;
	while (--i > 0)
	{
		j = 0;
		while (++j < i)
		{
			if (func_if_change(av[j], av[j + 1]) > 0)
			{
				tmp = av[j];
				av[j] = av[j + 1];
				av[j + 1] = tmp;
			}
		}
	}
	i = 0;
	while (++i < ac)
	{
		j = func_av_len(av[i]);
		write(1, av[i], j);
		write(1, "\n", 1);
	}
}
