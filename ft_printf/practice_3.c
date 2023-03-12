#include <unistd.h>
#include <stdarg.h>


int ft_putstr(char *string, int length)
{
    while (string && string[length] && ++length);
    return (string ? write(1, string, length) : write(1, "(null)", 6));
}

void ft_putnbr(long number, char *base, long length, int *size)
{
    if (number >= length)
        ft_putnbr(number / length, base, length, size);
    size += write(1, &base[number % length], 1);
}

int ft_print(char *format, ...)
{
    va_list ap;
    int size = 0;

    va_start(ap, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1) == 's' && *(format += 2))
            size += ft_putstr(va_arg(ap, char *), 0);
        else if (*format == '%' && *(format + 1) == 'd' && *(format += 2))
            ft_putnbr(va_arg(ap, int), "0123456789", 10, &size);
        else if (*format == '%' && *(format + 1) == 'x' && *(format += 2))
            ft_putnbr(va_arg(ap, int), "0123456789abcdef", 16, &size);
        else
            size += (int)write(1, format++, 1);
    }
    return (va_end(ap), size);
}




int main()
{

    ft_print("s test: %s\n", "hello my name is jeongeumseong!");
    ft_print("d test: %d\n", 123456);
    ft_print("x test: %x\n", 123456);
}