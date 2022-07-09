/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:32:03 by eunjeong          #+#    #+#             */
/*   Updated: 2022/05/25 11:32:05 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	func_printer(char a)
{
	write(1, &a, 1);
}

int	func_check_printalble(char the_char)
{
	if (the_char >= 32 && the_char < 127)
		return (the_char);
	else
		return (0);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	the_char;
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		the_char = str[i];
		if (func_check_printalble(the_char))
			func_printer(the_char);
		else
		{
			func_printer('\\');
			func_printer("0123456789abcdef"[the_char / 16]);
			func_printer("0123456789abcdef"[the_char % 16]);
		}
		i++;
	}
}
