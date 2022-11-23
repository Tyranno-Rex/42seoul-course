NAME = libftprintf.a

INC =  ./include/ft_printf.h

SRC_DIR = ./srcs/

SRC_NAME = 
	ft_libft_util.c /
	ft_printf.c /
	ft_putchar.c /
	# ft_puthex.c /
	# ft_putNSint.c /
	# ft_putpointer.c /
	# ft_putstring.c 

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJS = $(SRC:.c=.o)

flag = -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	gcc $(flag) -c $(SRC) -l $(INC) 
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re:
	flean all