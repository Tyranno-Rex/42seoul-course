
NAME		= push_swap

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

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f
OBJS		= $(SRCS:.c=.o)
LIBFT		= libft

all: $(NAME)

%.o: %.c
		@$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(NAME): $(OBJS) lib
		@$(CC) $(CFLAGS) -L $(LIBFT) -o $(NAME) $(OBJS) -l:libft.a

lib:
	@$(MAKE) -s -C $(LIBFT) bonus

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -s -C $(LIBFT) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFT) fclean

re: fclean $(NAME)

.PHONY: all lib clean fclean re create_progressbar
