/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:04:44 by marvin            #+#    #+#             */
/*   Updated: 2022/07/09 19:04:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strlen(char *str)
{
	int		the_num;

	the_num = 0;
	while (*str != '\0')
	{
		the_num++;
		str++;
	}
	return (the_num);
}

char	*strrchr(const char *str, int c)
{
	int		i;
	int		len;

	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == c)
			break ;
		len--;
	}
	if (i >= 0)
		return (str + i);
	return (NULL);
}
