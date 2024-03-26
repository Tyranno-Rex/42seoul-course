SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SERVER_SRCS = srcs/server.c
CLIENT_SRCS = srcs/client.c
SERVER_BONUS_SRCS = srcs_bonus/server_bonus.c
CLIENT_BONUS_SRCS = srcs_bonus/client_bonus.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:.c=.o)
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a

all: $(SERVER) $(CLIENT)

$(LIBFT):
	$(MAKE) -C ./libft
$(FT_PRINTF):
	$(MAKE) -C ./ft_printf

$(SERVER): $(SERVER_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT) $(FT_PRINTF) -o server
$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) $(FT_PRINTF) -o client
	
$(SERVER_BONUS): $(SERVER_BONUS_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) $(LIBFT) $(FT_PRINTF) -o server_bonus
$(CLIENT_BONUS): $(CLIENT_BONUS_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(LIBFT) $(FT_PRINTF) -o client_bonus

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