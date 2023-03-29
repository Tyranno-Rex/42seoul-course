#include <unistd.h>
#include <stdarg.h>

int ft_printf(char *format, ...)
{
    int         size = 0;
    va_list     ap;
    va_start(ap, format);

    while (*format)
    {
        if (*format == '%' && *(format + 1) == 's' && (format += 2))
            ft_putstr(va_arg(ap, char *), 0)
        else if (*format == '%' && *(format + 1) == 's' && (format += 2))
        else if (*format == '%' && *(format + 1) == 's' && (format += 2))
        else
            size += write(1, format++, 1);
    }
    
}