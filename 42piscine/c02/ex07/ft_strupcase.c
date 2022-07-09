/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:02:23 by eunjeong          #+#    #+#             */
/*   Updated: 2022/05/23 21:02:26 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	the_char;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		the_char = str[i];
		if (the_char >= 'a' && the_char <= 'z')
			str[i] = str[i] - ('a' - 'A');
		i++;
	}
	return (str);
}
