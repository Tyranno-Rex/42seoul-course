#include "include/ft_printf.h"

void ft_putchr(const char ch)
{   
    write(1, ch, 1);
}