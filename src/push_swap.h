
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
#include "../libft/libft.h"
// #include "../GNL/get_next_line.h"

typedef struct s_input
{
	int		ac;
	char	**av;
}	t_input;

typedef struct s_stack
{
	int		*arr;
	int		*check_arr;
	int		size;
	int		top;
	char	*line;
	t_input	input;
}	t_stack;

/*checker_ac_av.c*/
int		ft_check_ac_av(int ac, char **av);

/*main.c*/

/*parsing*/
char	**ft_parsing_stack_a(t_stack *push_swap_a);
void	ft_put_av2stack(t_stack *push_swap_a, char **line_2d);

/*sort.c*/
void bubble_sort(t_stack *push_swap_a);

/*stack_init.c*/
void	ft_stack_init(int ac, char **av, t_stack *push_swap_a, t_stack *push_swap_b);

/*utils.c*/
void	ft_show_error(char *msg);
int		ft_array_size(char **line_2d);

#endif
