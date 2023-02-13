
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#ifdef _WIN32
	#include <io.h>
#else
	#include <unistd.h>
#endif
#include <stddef.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>

#include "../ft_printf/ft_printf.h"
#include "../lib/libft.h"

typedef struct s_push_swap
{
	t_push_swap			*next;
	int					value;
	int					index;
	int					sort;
}	t_push_swap;

typedef struct s_stack
{
	t_push_swap	*a;
	t_push_swap	*b;
	t_push_swap	*sort;
	int			a_len;
	int			b_len;
}	t_stack;

/*main.c*/
int ft_check_is_sign(char c);
int ft_check_is_number(char *num);
int ft_check_ac_av(int ac, char **av);

/*push_value.c*/
t_push_swap	*stack_init(int nb);
void 		stack_add_bottom(t_push_swap **stack, t_push_swap *new);
t_stack		ft_push_stack(int len, char **av);

#endif
