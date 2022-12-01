#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#if _WIN32
    #include <io.h>
#else
    #include <unistd.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void	ft_putchar(char *info);
void    ft_putstring(char *info);
void	ft_putint(int n);
// int		ft_putpointer(va_list info);
// int		ft_putNSint(va_list info);
// int		ft_puthex(va_list info, const char format);

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format);

#endif