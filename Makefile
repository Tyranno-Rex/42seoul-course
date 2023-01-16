NAME = so_long

SRC = main.c

SCR_OBJ = $(SRC:.c=.o)
CC = cc
GCC = -Wall -Wextra -Werror
LMLX = -Imlx

%.o: %.c
	$(cc) $(GCC) $(LMLX) -c $< -o $@