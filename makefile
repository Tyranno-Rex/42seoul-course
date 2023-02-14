NAME = so_long
SRCS = image.c main.c map_can_clear.c map_checker.c map_copy.c map_info.c \
		map_read.c map_utils.c player_controller.c palyer_state.c struct_init.c \
		window_create.c window_draw.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAG = -Wall -Werror -Wextra
MLX = -lmlx -framework OpenGL -framework AppKit

all : extern $(NAME)

extern :
	make -C libft/
	make -C get_next_line/
	make -C ft_printf/

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)
	libft/libft.a get_next_line/libft_getnextline.a\
	ft_printf/libftprintf.a $(MLX)

%.o: %.c so_long.h
	make clean -C libft/
	make clean -C get_next_line/
	make clean -C ft_printf/
	rm -rf $(OBJS)

fclean : clean
	rm -rf libft/libft.a
	rm -rf get_next_line/libft_getnextline.a
	rm -rf ft_printf/libftprintf.a
	rm -rf $(NAME)

re : fclean all

.PHONY : all extern clean fclean re