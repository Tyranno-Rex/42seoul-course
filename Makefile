SERVER = server
CLIENT = client

SERVER_SRC = src/server.c
CLIENT_SRCS = src/client.c
SERVER_B_SRC = src/server_bonus.c
CLIENT_B_SRCS = src/client_bonus.c

SERVER_OBJS = $(SERVER_SRC:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_B_OBJS = $(SERVER_B_SRC:.c=.o)
CLIENT_B_OBJS = $(CLIENT_B_SRCS:.c=.o)

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
$(CLIENT): $(CLIENT_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(FT_PRINTF) $(LIBFT) -o client

bouns: ${SERVER_B_OBJS} ${CLIENT_B_OBJS}
	$(CC) $(CFLAGS) $(SERVER_B_OBJS) $(LIBFT) $(FT_PRINTF) -o server
	$(CC) $(CFLAGS) $(CLIENT_B_OBJS) $(FT_PRINTF) $(LIBFT) -o client

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./ft_printf
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) ${CLIENT_B_OBJS} ${SERVER_B_SRC}

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./ft_printf
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY : all re fclean clean