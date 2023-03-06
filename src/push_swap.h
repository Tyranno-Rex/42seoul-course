#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#ifdef _WIN32
	# include <io.h>
#else
	# include <unistd.h>
#endif
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

/*argument.c*/
char	*parsing_argv(int argc, char **argv);
int		arguments_len(char **argv);

/*argv_checker.c*/
void    atoi_pro(const char *the_char);
void	verif_args(char *argv);
int		space_only(char *argv);
void	check_ac_av(int argc, char **argv);

/*argv_checker_utils.c*/
void	check_dup(int argc_len, int *str_int);
int		check_atoi(char *str, int nb);

/*free.c*/
void	free_lst(t_stack **stack);
void	free_2D(char **tab_str);

/*movement.c*/
void	move_swap(t_stack **head, char c);
void	move_push(t_stack **stack_push, t_stack **stack_receive, char c);
void	move_rotate(t_stack **head, char c);
void	move_rev_rotate(t_stack **head, char c);

/*radix.c*/
void	radix_algo(t_stack **stack_a, t_stack **stack_b, int nbr_arg);
int		binary_len(int max);

/*small_movement.c*/
void	hard_case(t_stack **stack_a, t_stack **stack_b, int nbr_arg);
void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack_a);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_four(t_stack **stack_a, t_stack **stack_b);

/*stack.c*/
int		get_index(int num, int *tab, int nb);
void	create_stack_a(t_stack **stack_a, int num, int *str_int);
void	create_node(t_stack **head, int index);
void	check_order(t_stack *stack);

/*utils.c*/
void	show_error(char *msg);
void	show_free_error(char *msg, char *target);
void	show_free_error_2(char *msg, int *target);
int		*put_tab_int(int nbr_arg, char **tab_char);
int		check_atoi(char *str, int nb);

#endif