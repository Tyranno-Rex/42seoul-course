#include "../include/ft_printf.h"

void ft_putchar(char *info)
{
    write(1, &info, 1);
}