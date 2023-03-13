#include <unistd.h>
#include <stdarg.h>

size_t	ft_putstr(char *string, int length)
{
	while (string && string[length] && ++length);
	return (string ? write(1, string, length) : write(1, "(null)", 6));
}

void	ft_putnbr(long number, unsigned length, char *sign, int *size)
{
	if (number < 0)
	{
		*size += (int)write(1, "-", 1);
		number = number * -1;
	}
	if (number >= length)
		ft_putnbr(number / length, length, sign, size);
	*size += (int) write(1, &sign[number % length], 1);
}

int	ft_printf(char *format, ...)
{
	int		size = 0;
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) == 's' && (format += 2))
			size += (int) ft_putstr(va_arg(ap, char *), 0);
		else if (*format == '%' && *(format + 1) == 'x' && (format += 2))
			ft_putnbr(va_arg(ap, int), 16, "0123456789abcdef", &size);
		else if (*format == '%' && *(format + 1) == 'd' && (format += 2))
			ft_putnbr(va_arg(ap, int), 10, "0123456789", &size);
		else
			size += (int) write(1, format++, 1);
	}
	return (va_end(ap), size);
}

int main()
{
    ft_printf("%s\n", "hello my name is eunseong");
    ft_printf("%d\n", -12345678);
    ft_printf("%x\n", 12345678);
}