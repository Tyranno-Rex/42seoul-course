#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# ifdef _WIN32
	#include <io.h>
# else
	# include <unistd.h>
# endif
# include <stdio.h>

typedef struct s_push_swap
{
	int				val;
	int				i;
	int				sort;
	struct s_stack	*next;
}						t_push_swap;

typedef struct s_stacks
{
	t_push_swap			*a;
	t_push_swap			*b;
	t_push_swap			*max_sort;
	int				len_a;
	int				len_b;
	int				opt_a;
	int				opt_b;
	int				opt_pl;
	int				tmp_a;
	int				tmp_b;
	int				tmp_pl;
	int				cmd_print;
	int				cmd_cnt;
}						t_stacks;

int			get_count_nod(t_push_swap *stks);
t_push_swap		*create_new_nod(int val);
t_push_swap		*get_last_nod(t_push_swap *stack);
t_stacks	*create_stacks(int argc, char **argv);

int			free_stks(t_stacks **stks, int ret_num);
int			stk_set_tmp_cmd(t_stacks *stks, t_push_swap *tmp_b);
void		stk_copy_tmp_opt_cmd(t_stacks *stks);
void		put_error(t_stacks **stk, int ret_num);

void		push_back(t_push_swap **stack, t_push_swap *new);
void		push_front(t_push_swap **stack, t_push_swap *new);
t_push_swap		*push_back_int(t_push_swap **stack, int val);

t_push_swap		*pp_back(t_push_swap **stack);
t_push_swap		*pp_front(t_push_swap **stack);

void		stack_norm(t_stacks *stks);
void		nod_b_to_a(t_stacks	*stks);
void		stk_a_to_b(t_stacks	*stks);
void		stk_b_to_a(t_stacks	*stks);
void		stk_a_min_top(t_stacks *stks);

void		cmd_aap_cnt(char *com, int cnt, t_stacks *stks);

int			cmd_app_s(t_push_swap **stk);
int			cmd_app_r(t_push_swap **stk);
int			cmd_app_rr(t_push_swap **stk);
int			cmd_app_p(t_push_swap **st_dst, t_push_swap **st_src);

int			nod_itr_up(int stk_len, int nod_i);
int			nod_b_to_a_count(int a, int b, int plc_b);
int			get_nod_place_i(t_push_swap *stk, int nod_val);
void		set_index(t_push_swap *stk);
t_push_swap		*get_max_sort(t_push_swap *stk);

int			sort_stacks(t_stacks *stks);
int			sort_stacks_check(t_stacks *stks);
int			not_dubl(t_push_swap *stk, int val);
int			valid_int(int val_i, char *val_c);

#endif