/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:19:10 by eunjeong          #+#    #+#             */
/*   Updated: 2022/07/09 15:19:12 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*tmp;
	char	*tmp_to_tmp;

	i = 0;
	while (src[i])
		i++;
	tmp = malloc(sizeof(char) * i + 1);
	tmp_to_tmp = tmp;
	while (*src)
		*(tmp_to_tmp++) = *(src++);
	*tmp_to_tmp = '\0';
	return (tmp);
}
