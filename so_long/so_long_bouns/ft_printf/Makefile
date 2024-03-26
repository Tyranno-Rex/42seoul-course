SRC = ft_printf.c \
	ft_pointer_pf.c \
	ft_putchar_pf.c \
	ft_puthex_pf.c \
	ft_putint_pf.c \
	ft_putstring_pf.c

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