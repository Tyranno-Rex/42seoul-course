# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 20:23:05 by eunjeong          #+#    #+#              #
#    Updated: 2022/06/09 20:23:07 by eunjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
gcc -Wall -Wextra -Werror -c ft_putchar.c ft_swap.c ft_strcmp.c ft_strlen.c ft_putstr.c
ar -rc libft.a ft_putchar.o ft_swap.o ft_strcmp.o ft_strlen.o ft_putstr.o