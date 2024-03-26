NAME = push_swap

SRCS		= \
			src/arguments.c			\
			src/argv_checker.c		\
			src/argv_checker_utils.c\
			src/free.c				\
			src/hard_case.c			\
			src/main.c				\
			src/movements.c			\
			src/radix.c				\
			src/stack.c				\
			src/utils.c

OBJS = $(SRCS:.c=.o)
COMPILER = cc
CFLAGS = -Wall -Werror -Wextra

all: extern $(NAME)

extern:
	make -C libft/

$(NAME): $(OBJS)
	$(COMPILER) -o $(NAME) $(OBJS) libft/libft.a

%.o: %.c push_swap.h
	$(COMPILER) $(CFLAGS) -c $<

clean:
	make clean -C libft/
	rm -rf $(OBJS)

fclean: clean
	rm -rf libft/libft.a
	rm -rf $(NAME)

re: fclean all

.PHONY: all extern clean fclean re