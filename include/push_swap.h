
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
	int			cmd_cnt;
}	t_stack;

/*av_checker.c*/
int 		ft_check_is_sign(char c);
int 		ft_check_is_number(char *num);
int			ft_check_is_double();
int 		ft_check_ac_av(int ac, char **av);

/*stack_init.c*/
static void ft_setting_a(int len, char **av, t_stack *push_swap);
t_stack		*ft_push_swap_init(int len, char **av, t_stack *push_swap);

/*push_stack.c*/
int			ft_push_add_bottom();

#endif
