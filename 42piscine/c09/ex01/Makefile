SRCS	= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c
OBJS	= ${SRCS:.c=.o}
HEADER	= includes
NAME	= libft.a
CC		= gcc
RM		= rm -f

all: ${NAME}

.c.o:
	${CC} -Wall -Wextra -Werror  -c $< -o ${<:.c=.o} -I ${HEADER}

${NAME}: ${OBJS}
	ar -svrc ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all


.PHONY: all clean fclean re .c.o norm
