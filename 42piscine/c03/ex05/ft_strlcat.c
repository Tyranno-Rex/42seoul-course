/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 03:29:30 by eunjeong          #+#    #+#             */
/*   Updated: 2022/05/25 03:29:33 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	len_check(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	the_dest;
	unsigned int	the_src;
	unsigned int	i;

	the_dest = len_check(dest);
	the_src = len_check(src);
	if (size < the_dest)
		return (size + the_src);
	i = 0;
	while (src[i] && i + 1 < size - the_dest)
	{
		dest[the_dest + i] = src[i];
		i++;
	}
	dest[the_dest + i] = '\0';
	return (the_dest + the_src);
}
