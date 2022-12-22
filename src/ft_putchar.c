#include "../include/ft_printf.h"

int ft_putchar(char *info)
{
    write(1, &info, 1);
    return (1);
}