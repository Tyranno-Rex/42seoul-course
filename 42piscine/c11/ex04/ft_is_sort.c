/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:03:03 by eunjeong          #+#    #+#             */
/*   Updated: 2022/06/08 21:03:04 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		j;
	int		compare;

	i = -1;
	if (length < 3 && length > 0)
		return (1);
	while (tab[++i])
	compare = tab[++i] - tab[0];
	j = -1;
	while (++j < i - 1)
	{
		if (f(tab[j], tab[j + 1]) * compare < 0)
			return (0);
	}
	return (1);
}
