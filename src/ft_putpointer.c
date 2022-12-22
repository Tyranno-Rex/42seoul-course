#include "../include/ft_printf.h"

int ft_ptr_len(uintptr_t num)
{
    int len;

    len = 0;
    while (num != 0)
    {
        // num /= 16;
        num = num / 16;
        len++;
    }
    return (len);
}

void ft_putPTR(uintptr_t n)
{
    if (n >= 16)
    {
        ft_putPTR(n/16);
        ft_putPTR(n%16);
    }
    else
    {
        if (n <= 9)
            ft_putchar(n + '0');
        else
            ft_putchar(n - 10 + 'a');
    }
}

int ft_putpointer(unsigned long long info)
{
    int ptr_len;

    ptr_len = 0; 
    ptr_len += write(1, "0x", 2);
    if (info  == 0)
        ptr_len += write(1,"0", 1);
    else
    {
        ft_putPTR(info);
        ptr_len += ft_ptr_len(info);
    }
    return (ptr_len);
}