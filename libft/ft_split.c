/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:42:02 by marvin            #+#    #+#             */
/*   Updated: 2022/07/15 19:42:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	func_str_num(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (!s[0])
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			cnt++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		cnt++;
	return (cnt);
}

void	func_find_next(char **str, size_t *str_len, char c)
{
	size_t	i;

	*str += *str_len;
	*str_len = 0;
	i = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*str_len)++;
		i++;
	}
}

char	**func_mem_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *str, char charset)
{
	char	**tmp;
	char	*next_str;
	size_t	next_strlen;
	int		i;

	if (!str)
		return (NULL);
	tmp = malloc(sizeof(char *) * (func_str_num(str, charset) + 1));
	if (!tmp)
		return (NULL);
	i = -1;
	next_str = (char *)str;
	next_strlen = 0;
	while (++i < func_str_num(str, charset))
	{
		func_find_next(&next_str, &next_strlen, charset);
		tmp[i] = (char *)malloc(sizeof(char) * (next_strlen + 1));
		if (!tmp[i])
			return (func_mem_free(tmp));
		ft_strlcpy(tmp[i], next_str, next_strlen + 1);
	}
	tmp[i] = NULL;
	return (tmp);
}
