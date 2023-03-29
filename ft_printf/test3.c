#include <unistd.h>
#include <stdarg.h>
int ft_putstr(char *string, int size)
{
    while (string && string[size] && (++size));
    return (string ? write(1, string, size) : write(1, "(null)", 6));
}

void ft_putnbr(long number, char *base, int length, int *size)
{
    if (number < 0)
    {
        number = number * -1;
        *size +=write(1, "-", 1);
    }
    if (number >= length)
        ft_putnbr(number/length, base, length, size);
    *size += write(1, &base[number%length], 1);
}

int ft_printf(char *format, ...)
{
    int size = 0;
    va_list ap;
    va_start (ap, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1) == 's' && (format += 2))
            size += ft_putstr(va_arg(ap, char *), 0);
        else if (*format == '%' && *(format + 1) == 'd' && (format += 2))
            ft_putnbr(va_arg(ap, int), "0123456789", 10, &size);
        else if (*format == '%' && *(format + 1) == 'x' && (format += 2))
            ft_putnbr(va_arg(ap, int), "0123456789abcdef", 16, &size);
        else
            size += write(1, format++, 1);
    }
    return (va_end(ap), size);
}
int main()
{
    int size = 0;
    size += ft_printf("%s\n", "hello my name is jeongeunseong");
    size += ft_printf("%d\n", size);
    size += ft_printf("%x\n", size);
}