/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 03:39:55 by eunjeong          #+#    #+#             */
/*   Updated: 2022/05/25 03:39:59 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	func_not_same(char s1, char s2)
{
	if (s1 > s2)
		return (1);
	else
		return (-1);
}

void	func_check(char s1, char s2, int *the_check)
{
	if (s1 == '\0')
		the_check[0] = 1;
	if (s2 == '\0')
		the_check[1] = 1;
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;
	int		the_check[2];

	i = 0;
	the_check[0] = 0;
	the_check[1] = 0;
	while (the_check[0] != 1 && the_check[0] != 1)
	{
		if (s1[i] != s2[i])
		{
			i = func_not_same(s1[i], s2[i]);
			return (i);
		}
		func_check(s1[i], s2[i], the_check);
		i++;
	}
	return (0);
}
