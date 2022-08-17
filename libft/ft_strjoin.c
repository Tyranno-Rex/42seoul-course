/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:04:07 by marvin            #+#    #+#             */
/*   Updated: 2022/07/25 16:57:21 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 수정함 확인하기
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*ret;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!(ret))
		return (0);
	ft_strlcpy(ret, s1, len_s1 + 1);
	ft_strlcpy(ret, s2, len_s1 + len_s2 + 1);
	// ft_memcpy(ret, s1, len_s1);
	// ft_memcpy(ret + len_s1, s2, len_s2);
	// ret[len_s1 + len_s2] = 0;
	return (ret);
}
