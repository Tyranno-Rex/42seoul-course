/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:06:03 by eunjeong          #+#    #+#             */
/*   Updated: 2022/05/27 10:44:01 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	the_pos;

	the_pos = 0;
	while (src[the_pos] != '\0' && the_pos < n)
	{
		dest[the_pos] = src[the_pos];
		the_pos++;
	}
	while (the_pos < n)
	{
		dest[the_pos] = '\0';
		the_pos++;
	}
	return (dest);
}
