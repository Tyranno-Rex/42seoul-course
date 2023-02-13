NAME = so_long

SRCS = src/image.c src/main.c src/map_can_clear.c \
			src/map_checker.c src/map_copy.c src/map_info.c \
			src/map_read.c src/map_utils.c src/player_controller.c \
			src/player_state.c src/struct_init.c src/window_create.c \
			src/window_draw.c

OBJS = $(SRCS:.c=.o)
COMPILER = cc
CFLAGS = -Wall -Werror -Wextra
MLX = -lmlx -framework OpenGL -framework AppKit

all: extern $(NAME)

extern:
	make -C lib/

$(NAME): $(OBJS)
	$(COMPILER) -o $(NAME) $(OBJS) lib/libft.a $(MLX)

%.o: %.c so_long.h
	$(COMPILER) $(CFLAGS) -c $<

clean:
	make clean -C lib/
	rm -rf $(OBJS)

fclean: clean
	rm -rf lib/libft.a
	rm -rf $(NAME)

re: fclean all

.PHONY: all extern clean fclean re