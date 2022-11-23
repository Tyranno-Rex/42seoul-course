#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#if _WIN32
    #include <io.h>
#else
    #include <unistd.h>
#endif
#include <stdlib.h>
#include <cstdlib>

int		ft_putchar(va_list info);
int		ft_putstring(va_list info);
int		ft_putpointer(va_list info);
int		ft_putint(va_list info);
int		ft_putNSint(va_list info);
int		ft_puthex(va_list info, const char format);

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format);

#endif