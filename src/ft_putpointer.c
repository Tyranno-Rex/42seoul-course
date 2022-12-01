#include "../include/ft_printf.h"


void ft_putPTR(int n)
{
    int i = 0;
    
    while (n >= 0)
    {
        n = n / 16;
        i++;
    }

}

void ft_putpointer(int info)
{
    write(1, "0x", 2);
    if (info  == 0)
    {
        write(1,"0", 1);
    }
    else
    {
        ft_putPTR(info);
    }
}