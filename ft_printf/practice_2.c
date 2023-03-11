#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>

int ft_putstr(char *str, int len)
{
    while (str && str[len], len++)
    {
        /* code */
    }
    
}



int ft_printf(char *str, ...)
{
    va_list ap;
    int     size = 0;

    va_start(ap, str);

    while (*str)
    {
        if (*str == '%' && (*str + 1) == 's' && (*str += 2))
            size += ft_putstr(va_arg(ap, char *), 0);
    }
    return (va_end(ap), size);
}

int main()
{
    ft_printf("%s\n", "hello my name is eunseong");
}