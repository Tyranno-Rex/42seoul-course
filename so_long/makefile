NAME = so_long
SRCS =  image_render.c image_setting.c main.c map_checker.c map_is_clear.c\
		map_reader.c map_utils.c player_controller.c so_long_utils.c struct_init.c

OBJS = $(SRCS:.c=.o)
COMPILER = cc
CFLAGS = -Wall -Werror -Wextra

all: extern $(NAME)

extern:
	make -C libft/
	make -C ft_printf/
	make -C get_next_line/

$(NAME): $(OBJS)
	$(COMPILER) -o $(NAME) $(OBJS) \
	libft/libft.a ft_printf/libftprintf.a \
	get_next_line/libft_getnextline.a \
	-lmlx -framework OpenGL -framework AppKit

%.o: %.c so_long.h
	$(COMPILER) $(CFLAGS) -c $<

clean:
	make clean -C libft/
	make clean -C ft_printf/
	make clean -C get_next_line/
	rm -rf $(OBJS)

fclean: clean
	rm -rf libft/libft.a
	rm -rf ft_printf/libftprintf.a
	rm -rf get_next_line/libft_getnextline.a
	rm -rf $(NAME)

re: fclean all

.PHONY: all extern clean fclean re