/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:54:54 by eunjeong          #+#    #+#             */
/*   Updated: 2022/12/23 15:34:32 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#ifdef _WIN32
    #include <io.h>
#else
    # include <unistd.h>
#endif

# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_percent_pf(const char format, va_list info);

int		ft_pointer_pf(void *p);
int		ft_putptr_pf(size_t nbr);
int		ft_puthex_pf(unsigned int nbr, char *b);
int		ft_putstring_pf(char *info);

int		ft_putchar_pf(int c);
int		ft_putint_pf(long long n);
size_t	ft_strlen_pf(const char *s);

#endif