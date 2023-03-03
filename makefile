PUSH_SWAP = push_swap
PUSH_SWAP_SRC = src/main.c src/check_ac_av.c src/parsing.c \
		src/stack_init.c src/utils.c src/sort.c
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRC:.c=.o)

CC = cc
# CFLAGS = 
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a

all: $(PUSH_SWAP)

$(LIBFT):
	$(MAKE) -C ./libft
$(FT_PRINTF):
	$(MAKE) -C ./ft_printf

$(PUSH_SWAP) : $(PUSH_SWAP_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) $(LIBFT) $(FT_PRINTF) -o push_swap

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./ft_printf
	$(RM) $(PUSH_SWAP_OBJS)

fclean: clean
	$(RM) ./libft/libft.a
	$(RM) ./ft_printf/libftprintf.a
	$(RM) $(PUSH_SWAP)

re: fclean all

.PHONY : all re fclean clean bonus