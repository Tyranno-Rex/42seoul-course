SRCS = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c 
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c

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

.PHONY: all bonus clean fclean re