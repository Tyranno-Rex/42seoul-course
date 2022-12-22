#include "../include/ft_printf.h"

// cspdiuxX
void	ft_percent(const char format, va_list info)
{
	if (format == 'c')
		ft_putchar(va_arg(info, char *));
	else if (format == 's')
		ft_putstring(va_arg(info, char *));
	else if (format == 'p')
		ft_putpointer(va_arg(info, unsigned long long));
	else if (format == 'd' || format == 'i')
		ft_putint(va_arg(info, int));
	else if (format == 'u')
		ft_putNSint(va_arg(info, unsigned int));
	// else if (format == 'x' || format == 'X')
	// 	ft_puthex(info, format);
	// else if (format == '%')
	// 	printf("error");
	// else
	// 	printf("error");
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
			ft_percent(format[i + 1], ap);
			i++;
		}
		else
			printf("%c", format[i]);
		i++;
	}
	return (0);
}