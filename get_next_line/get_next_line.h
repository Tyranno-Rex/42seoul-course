/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:55:22 by eunjeong          #+#    #+#             */
/*   Updated: 2022/11/19 11:55:24 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

#ifdef _WIN32
    #include <io.h>
#else
    #include <unistd.h>
#endif

size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strchr(const char *str, int c);
char	*ft_gnl_substr(char const *s, unsigned int base, size_t len);
char	*ft_gnl_strjoin(char *buf, char *s);

char	*ft_gnl_update_str(char *buf);
char	*ft_gnl_return_str(char *buf);
char	*ft_gnl_read_str(int fd, char *buf);
char	*get_next_line(int fd);

#endif
