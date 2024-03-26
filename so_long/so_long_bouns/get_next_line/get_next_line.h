/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:03:22 by eunjeong          #+#    #+#             */
/*   Updated: 2022/11/19 16:43:59 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifdef _WIN32
#  include <io.h>
# else
#  include <unistd.h>
# endif
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t		ft_strlen_pro(const char *s, char c);
size_t		ft_strlen_gnl(char const *str);
char		*ft_strchr_gnl(char const *s, int c);
char		*ft_strdup_gnl(char const *str);
char		*ft_strjoin_gnl(char *s1, char *s2);
char		*ft_substr_gnl(char const *str, unsigned int start, size_t len);
char		*get_next_line(int fd);
#endif