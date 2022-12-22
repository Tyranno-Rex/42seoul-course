#include "../include/ft_printf.h"


void ft_putPTR(intptr_t n)
{
    char c;

    if (n >= 16)
    {
        ft_putPTR(n/16);
        ft_putPTR(n%16);
    }
    else
    {
        if (n <= 9)
        {
            c = ft_itoa(n);
            ft_putchar(c);
        }
        else
        (
            if (n == 10)
                ft_putchar('A');

        )
    }
}

void ft_putpointer(int info)
{
    int ptr_len;

    ptr_len = 0; 
    ptr_len += write(1, "0x", 2);
    if (info  == 0)
        ptr_len += write(1,"0", 1);
    else
    {
        ft_putPTR(info);
        ptr_len += ft_putPTR(info);
    }
    return (ptr_len);
}