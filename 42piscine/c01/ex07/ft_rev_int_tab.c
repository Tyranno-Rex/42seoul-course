/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:39:45 by eunjeong          #+#    #+#             */
/*   Updated: 2022/05/21 23:39:47 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	the_num;
	int	the_tmp;

	the_num = 0;
	while (the_num < size / 2)
	{
		the_tmp = tab[the_num];
		tab[the_num] = tab[size - the_num -1];
		tab[size - the_num - 1] = the_tmp;
		the_num++;
	}
}
