SRCS	= ./src/main.c ./src/func_printer.c ./src/func_calculator.c
OBJS	= ${SRCS:.c=.o}
HEADER	= includes
NAME	= do-op
CC		= gcc
RM		= rm -f

.c.o:
	${CC} -Wall -Wextra -Werror -c $< -o ${<:.c=.o} -I ${HEADER}

${NAME}: ${OBJS}
	ar -svrc ${NAME} ${OBJS}

	# ${cc} -Wall -Wextra -Werror ${OBJS} -o ${NAME}
all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re .c.o
