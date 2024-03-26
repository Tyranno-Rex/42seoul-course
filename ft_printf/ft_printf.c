/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:55:08 by eunjeong          #+#    #+#             */
/*   Updated: 2022/12/23 15:48:29 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent(const char format, va_list info)
{
	int	info_len;

	info_len = 0;
	if (format == 'c')
		info_len += ft_putchar(va_arg(info, int));
	else if (format == 's')
		info_len += ft_putstring(va_arg(info, char *));
	else if (format == 'p')
		info_len += ft_pointer(va_arg(info, void *));
	else if (format == 'd' || format == 'i')
		info_len += ft_putint(va_arg(info, int));
	else if (format == 'u')
		info_len += ft_puthex(va_arg(info, int), "0123456789");
	else if (format == 'x')
		info_len += ft_puthex(va_arg(info, int), "0123456789abcdef");
	else if (format == 'X')
		info_len += ft_puthex(va_arg(info, int), "0123456789ABCDEF");
	else if (format == '%')
		info_len += ft_putchar('%');
	else
		info_len += ft_putchar(va_arg(info, int));
	return (info_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (format == NULL)
		return (0);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_percent(format[i + 1], ap);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
