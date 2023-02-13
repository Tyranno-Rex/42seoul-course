SO_LONG = SO_LONG

SO_LONG_SRCS = src/image.c src/main.c src/map_can_clear.c \
			src/map_checker.c src/map_copy.c src/map_info.c \
			src/map_read.c src/map_utils.c src/player_controller.c \
			src/player_state.c src/struct_init.c src/window_create.c \
			src/window_draw.c

SO_LONG_OBJS = $(SO_LONG_SRCS:.c=.o)

AR = ar rcs
CC = cc
CFLAGS = -Wextra -Werror
INC = ./include

RM = rm -rf
MLX = -L./mlx_lib -lmxl -framework OpenGL -framework Appkit


LIBFT = ./lib/libft.a


all: $(SO_LONG)

$(LIBFT):
	$(MAKE) -C ./libft

$(SO_LONG): $(SO_LONG_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SO_LONG_OBJS) -I $(INC) $(LIBFT) $(MLX) -o SO_LONG

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(SO_LONG_OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft ./ft_printf
	$(RM) $(SO_LONG)

re: fclean all

.PHONY : all re fclean clean bonus