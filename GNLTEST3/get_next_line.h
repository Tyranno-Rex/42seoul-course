/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:39:27 by eunjeong          #+#    #+#             */
/*   Updated: 2022/08/12 16:47:37 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifdef _WIN32
#  include <io.h>
# else
#  include <unistd.h>
# endif

# include <stdlib.h>  //malloc함수 선언
# include <limits.h>  //OPEN_MAX 선언

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# define FT_EOF 0
# define FT_SUCCESS 1
# define FT_FAIL -1

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t num);
size_t	ft_strlen(const char *str);
char	*ft_strndup(const char *str, ssize_t offst);

#endif