/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:03:15 by eunjeong          #+#    #+#             */
/*   Updated: 2022/05/22 21:03:18 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int		the_pos;

	the_pos = 0;
	while (src[the_pos] != '\0')
	{
		dest[the_pos] = src[the_pos];
		the_pos++;
	}
	dest[the_pos] = '\0';
	return (dest);
}
