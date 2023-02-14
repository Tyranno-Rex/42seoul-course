/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:10:45 by eunjeong          #+#    #+#             */
/*   Updated: 2022/11/19 16:43:50 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
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

char	*ft_strchr_gnl(const char *s, int c)
{
	char	find;
	int		i;

	find = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == find)
		return ((char *)s + i);
	return (0);
}

char	*ft_strdup_gnl(char const *str)
{
	char	*dup;
	char	*ptr;

	dup = malloc (sizeof (*dup) * (ft_strlen_gnl(str) + 1));
	if (!dup)
		return (0);
	ptr = dup;
	while (*str)
		*ptr++ = *str++;
	*ptr = 0;
	return (dup);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*s3;
	char	*p3;
	char	*p1;

	if (!s1 || !s2)
		return (0);
	s3 = malloc (sizeof (*s3) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!s3)
	{
		free (s1);
		free (s2);
		return (0);
	}
	p3 = s3;
	p1 = s1;
	while (*p1)
		*p3++ = *p1++;
	while (*s2)
		*p3++ = *s2++;
	*p3 = 0;
	free (s1);
	return (s3);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	if (!s)
		return (0);
	if (start >= ft_strlen_gnl(s))
		return (ft_strdup_gnl(""));
	if (len > ft_strlen_gnl(s))
	{
		len = ft_strlen_gnl(s);
		tmp = (char *)malloc(len - start + 1);
	}
	else
		tmp = (char *)malloc(len + 1);
	if (!tmp)
		return (0);
	*(tmp + len) = 0;
	i = 0;
	while (i < len && *(s + start + i))
	{
		*(tmp + i) = *(s + start + i);
		i++;
	}
	return (tmp);
}
