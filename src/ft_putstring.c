#include "../include/ft_printf.h"

int ft_putstring(char *info)
{
    int i = 0;
    while (info[i])
    {
        write(1, &info[i], 1);
        i++;
    }
    return (i);
}