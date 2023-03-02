
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#ifdef _WIN32
	#include <io.h>
#else
	#include <unistd.h>
#endif

#include <stdbool.h>
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

typedef struct s_input
{
	int		ac;
	char	**ag;
}	t_input;

typedef struct s_structure
{
	int		*arr;
	int		*c_arr;
	int		top;
	int		size;
	char	*line;
	t_input	input;
}	t_stack;



/*checker_ac_av.c*/
int	ft_check_ac_av(int ac, char **av);

/*main.c*/

/*stack_init.c*/
void ft_stack_init(int ac, char **av, t_stack *push_swap);

/*utils.c*/
void ft_show_error(char *msg);

#endif
