/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:11:54 by eunjeong          #+#    #+#             */
/*   Updated: 2022/05/25 11:12:00 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	func_check(char *str, int i)
{
	if (i == 0)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - ('a' - 'A');
	}
	if ((str[i] < 48) || (57 < str[i] && str[i] < 65) \
	|| (90 < str[i] && str[i] < 97) || (str[i] >= 123))
	{
		if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
			str[i + 1] = str[i + 1] - ('a' - 'A');
	}
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + ('a' - 'A');
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		func_check(str, i);
		i++;
	}
	return (str);
}
