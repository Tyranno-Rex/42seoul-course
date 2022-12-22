#include "../include/ft_printf.h"

int ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

// cspdiuxX
int		ft_percent(const char format, va_list info)
{
	int info_len;

	info_len = 0;
	if (format == 'c')
		info_len += ft_putchar(va_arg(info, char *));
	else if (format == 's')
		info_len += ft_putstring(va_arg(info, char *));
	else if (format == 'p')
		info_len += ft_putpointer(va_arg(info, unsigned long long));
	else if (format == 'd' || format == 'i')
		info_len += ft_putint(va_arg(info, int));
	else if (format == 'u')
		info_len += ft_putNSint(va_arg(info, unsigned int));
	else if (format == 'x' || format == 'X')
		info_len += ft_puthex(va_arg(info, unsigned int), format);
	return (info_len);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int len, i;

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
			len += ft_print_char(format[i]);
		i++;
	}
	return (0);
}