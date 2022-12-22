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

int	ft_printf(const char *format, ...);


int		ft_putchar(char *info);
int		ft_putstring(char *info);
int		ft_putpointer(unsigned long long info);
int		ft_putint(int n);
int		ft_putNSint(unsigned int n);
int		ft_puthex(unsigned int info, const char format);

int     ft_print_char(int c);
void    ft_putPTR(uintptr_t n);
int     ft_ptr_len(uintptr_t num);
int 	ft_print_int(char *str);
char	*ft_itoa(int n);
int		ft_func_len(int n);
char	*func_arr(char *c, unsigned int number, int len);
int 	ft_print_int_ns(char *str);
char 	*ft_itoa_ns(unsigned int n);
int		func_len_ns(unsigned int n);
char	*func_arr_ns(char *c, unsigned int number, int len);
void	ft_print_hex(unsigned int num, const char format);
int		ft_hex_len(unsigned	int num);

#endif