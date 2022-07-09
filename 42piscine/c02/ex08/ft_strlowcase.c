/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:11:52 by eunjeong          #+#    #+#             */
/*   Updated: 2022/05/23 21:11:56 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	the_char;
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{
		the_char = str[i];
		if (the_char >= 'A' && the_char <= 'Z')
			str[i] = str[i] + ('a' - 'A');
	}
	return (str);
}
