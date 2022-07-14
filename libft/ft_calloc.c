/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:53:26 by eunjeong          #+#    #+#             */
/*   Updated: 2022/07/09 14:53:27 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int		i;

	register *result;
	i = -1;
	*result = (int *)malloc(nmemb * size);
	while (++i < nmemb * size)
		result[i] = 0;
	return (result);
}
