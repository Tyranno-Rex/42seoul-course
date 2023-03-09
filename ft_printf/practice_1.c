#include <io.h>
#include <stdarg.h>


int ft_putstr(char *msg)
{
    int length = 0;

    while (msg && msg[length])
        length++;
    if (!msg)
        write(1, "(null)", 6);
    else
        write(1, msg, length);
}

void ft_putint(int number, unsigned int length, char *str, int *size)
{
    if (number >= length)
        ft_putint(number/length, length, str, size);
    *size += (int) write(1, &str[number%length], 1);
}

int ft_printf(char *str, ...)
{
    int size = 0;
    va_list ap;

    va_start(ap, str);
    while (*str)
    {
        if (*str == '%' && *(str + 1) == 's')
        {
            str += 2;
            size += (int) ft_putstr(va_arg(ap, char *));
        }
        else if (*str == '%' && *(str + 1) == 'd')
        {
            str += 2;
            ft_putint(va_arg(ap, int), 10, "0123456789", &size);
        }
        else if (*str == '%' && *(str + 1) == 'x')
        {
            str += 2;
            ft_putint(va_arg(ap, int), 16, "0123456789abcdef", &size);
        }
        else
            size += (int) write(1, str++, 1);
    }
}

int main()
{
    ft_printf("%s\n", "hello my name is eunseong");
    ft_printf("%s\n");
    ft_printf("%d\n", 12345678);
    ft_printf("%x\n", 12345678);
}