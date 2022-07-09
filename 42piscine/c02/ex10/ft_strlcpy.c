/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:32:09 by eunjeong          #+#    #+#             */
/*   Updated: 2022/06/02 17:42:45 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	func_len(char *the_char)
{
	int		i;

	i = 0;
	while (the_char[i] != 0)
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = func_len(src);
	while (i < size)
	{
		if (i == size - 1)
		{
			dest[i] = '\0';
			return (j);
		}
		dest[i] = src[i];
		i++;
	}
	return (j);
}
