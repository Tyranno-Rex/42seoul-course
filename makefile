PUSH_SWAP = push_swap
PUSH_SWAP_SRC = src/main.c src/check_ac_av.c src/parsing.c src/stack_init.c src/utils.c
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
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	$(RM) $(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS) 
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(SERVER) $(CLIENT)
	$(RM) $(SERVER_BONUS) $(CLIENT_BONUS)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

.PHONY : all re fclean clean bonus