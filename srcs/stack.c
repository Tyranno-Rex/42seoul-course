#include "push_swap.h"

// s_2
static void	create_stack_a(int argc, char **argv, t_stacks *stks)
{
	int	i;
	int	cr_val;

	if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			cr_val = ft_atoi(argv[i]);
			if (valid_int(cr_val, argv[i]) == 0 
				|| not_dubl(stks->a, cr_val) == 0)
				put_error(&stks, ft_free_array(NULL, 1));
			// 1. a stack에 값을 넣음
			if ((push_back_int(&stks->a, cr_val)) == NULL)
				put_error(&stks, ft_free_array(NULL, 1));
			i++;
		}
	}
	return ;
}

// 3. a stack에 값을 넣음
t_stack	*create_new_nod(int val)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->val = val;
	new->i = 0;
	new->sort = 1;
	new->next = NULL;
	return (new);
}

// s_1
t_stacks	*create_stacks(int argc, char **argv)
{
	t_stacks	*stks;

	stks = (t_stacks *)malloc(sizeof(t_stacks));
	if (stks == NULL)
		put_error(&stks, 1);
	stks->a = NULL;
	stks->b = NULL;
	stks->cmd_cnt = 0;
	stks->cmd_print = 0;
	create_stack_a(argc, argv, stks);
	return (stks);
}


t_stack	*get_last_nod(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	get_count_nod(t_stack *stk)
{
	int	count;

	count = 0;
	while (stk)
	{
		stk = stk->next;
		count++;
	}
	return (count);
}
