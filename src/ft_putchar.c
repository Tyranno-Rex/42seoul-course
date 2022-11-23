#include "../include/ft_printf.h"

void ft_putchar(va_list info)
{
    write(1, info, 1);
}