NAME = philo

SRCS =  philo.c			\
		philo_utils.c	\
		philo_utils_2.c	\
		init_thread.c	\
		init_mutex.c	\
		launch_thread.c	\
		launch_waiter.c

OBJS = ${SRCS:.c=.o}

INCLUDE =	-I include

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -pthread

.c.o:		${SRCS}
			${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${OBJS} ${CFLAGS} ${INCLUDE} -o ${NAME}

all: 		${NAME}

clean:
			rm -f *.o

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all fclean clean re debug sani
