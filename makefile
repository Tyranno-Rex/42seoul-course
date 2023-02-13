# NAME = so_long

# SRCS = image.c main.c map_can_clear.c \
# 			map_checker.c map_copy.c map_info.c \
# 			map_read.c map_utils.c player_controller.c \
# 			player_state.c struct_init.c window_create.c \
# 			window_draw.c

# OBJS = $(SRCS:.c=.o)
# COMPILER = cc
# CFLAGS = -Werror -Wextra

# all: $(NAME)

# LIB:
# 	$(make) -C ./lib

# $(NAME): $(OBJS)
# 	$(COMPILER) -o $(NAME) $(OBJS) $(LIB) $(MLX)

# %.o: %.c so_long.h
# 	$(COMPILER) $(CFLAGS) -c $<

# clean:
# 	make clean -C lib/
# 	rm -rf $(OBJS)

# fclean: clean
# 	rm -rf lib/libft.a
# 	rm -rf $(NAME)

# re: fclean all

# .PHONY: all extern clean fclean re



SO_LONG = so_long

SO_LONG_SRC = image.c main.c map_can_clear.c \
			map_checker.c map_copy.c map_info.c \
			map_read.c map_utils.c player_controller.c \
			player_state.c struct_init.c window_create.c \
			window_draw.c


SO_LONG_OBJS = $(SO_LONG_SRC:.c=.o)

CC = cc
CFLAGS = -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

LIB = ./lib/libft.a

all: $(SO_LONG)

$(LIB):
	$(MAKE) -C ./lib


$(SO_LONG) : $(SO_LONG_OBJS) $(LIB)
	$(CC) $(CFLAGS) $(SO_LONG_OBJS) $(LIBFT) $(MLX) -o so_long

clean:
	$(MAKE) clean -C ./lib
	$(RM) $(SO_LONG_OBJS)

fclean: clean
	$(MAKE) fclean -C ./lib
	$(RM) $(SO_LONG)

re: fclean all

.PHONY : all re fclean clean bonus