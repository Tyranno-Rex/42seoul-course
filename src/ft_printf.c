#include "ft_printf.h"


int		ft_printf(const char *format, ...){
    va_list ap;
    int len;
    
    if (format == NULL)
        return (0);
    va_start(ap, format);
    
}