SRC = ft_printf.c \
	ft_pointer.c \
	ft_putchar.c \
	ft_puthex.c \
	ft_putint.c \
	ft_putstring.c

SRC_OBJ = $(SRC:.c=.o)

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = ar rcs
RM = rm -f

all : $(NAME)

$(NAME): $(SRC_OBJ)
		$(LIB) $(NAME) $(SRC_OBJ)
clean:
		$(RM) $(SRC_OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all