#include "ft_printf.h"


void ft_percent(const char format, va_list info)
{
    if (format == 'd' || format == 'i')
        ft_putint(info);
    else if (format == 'c')
        ft_putchar(info);
    else if (format == 's')
        ft_putchar(info);
    else if (format == 'p')
        ft_putchar(info);
    else if (format == 'u')
        ft_putchar(info);
    else if (format == 'x' || format == 'X')
        ft_putchar(info);
    else if (format == '%')
        printf();
    else
        printf();

}


int		ft_printf(const char *format, ...)
{
    va_list ap;
    int len, i;
    
    if (format == NULL)
        return (0);
    va_start(ap, format);
    while (format[i] != NULL)
    {
        if (format[i] == '%')
            ft_percent(format[i + 1], ap);
        else
            ft_putchr(format[i + 1]);
        i++;
    }
    
}