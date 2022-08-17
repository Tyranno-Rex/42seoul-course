/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:16:45 by marvin            #+#    #+#             */
/*   Updated: 2022/07/25 16:52:00 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > start)
			end--;
		str = (char *)malloc(sizeof(char) * (end - start + 1));
		if (str)
			ft_strlcpy(str, &s1[start], end - start + 1);
	}
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	back;
	char	*tmp_ptr;
	char	*trimed_str;

	if (!s1 || !set)
		return (NULL);
	front = 0;
	back = 0;
	tmp_ptr = (char *)s1;
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	back = ft_strlen(tmp_ptr + front);
	if (back > 0)
		while (tmp_ptr[back + front - 1] &&
				ft_strchr(set, tmp_ptr[back + front - 1]))
			back--;
	if (!(trimed_str = (char *)malloc(back * sizeof(char) + 1)))
		return (NULL);
	ft_strlcpy(trimed_str, tmp_ptr + front, back + 1);
	trimed_str[back] = '\0';
	return (trimed_str);
}