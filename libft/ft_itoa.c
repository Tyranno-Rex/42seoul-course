/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:45:17 by marvin            #+#    #+#             */
/*   Updated: 2022/07/15 19:45:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_abs(int n)
{
	long long	long_n;

	long_n = n;
	if (n < 0)
		return (long_n * -1);
	return (long_n);
}

int	ft_len(int n)
{
	int			len;
	long long	long_n;

	len = 1;
	long_n = ft_abs(n);
	while (long_n > 0)
	{
		len++;
		long_n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	long long	long_n;
	int			i;
	int			len;

	long_n = ft_abs(n);
	i = 1;
	len = ft_len(n);
	if (n < 0)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	while (i <= len)
	{
		if (str[len - i] != '-')
			str[len - i] = (long_n % 10) + '0';
		long_n /= 10;
		i++;
	}
	str[len] = '\0';
	return (str);
}
