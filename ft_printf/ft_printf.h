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

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_percent(const char format, va_list info);

int		ft_pointer(void *p);
int		ft_putptr(size_t nbr);
int		ft_putchar(int c);
int		ft_puthex(unsigned int nbr, char *b);
int		ft_putint(long long n);
int		ft_putstring(char *info);

size_t	ft_strlen(const char *s);
#endif