#include "push_swap.h"

t_push_swap	*create_new_nod(int val)
{
	t_push_swap	*new;

	new = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (new == NULL)
		return (NULL);
	new->val = val;
	new->i = 0;
	new->sort = 1;
	new->next = NULL;
	return (new);
}

t_push_swap	*get_last_nod(t_push_swap *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	push_back(t_push_swap **stk, t_push_swap *new)
{
	t_push_swap	*last;

	if (*stk == NULL)
	{
		*stk = new;
		return ;
	}
	last = get_last_nod(*stk);
	last->next = new;
}

t_push_swap	*push_back_int(t_push_swap **stk, int val)
{
	t_push_swap	*new;

	new = create_new_nod(val);
	if (new == NULL)
		return (NULL);
	push_back(stk, new);
	return (*stk);
}

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
			if ((push_back_int(&stks->a, cr_val)) == NULL)
				put_error(&stks, ft_free_array(NULL, 1));
			i++;
		}
	}
	return ;
}


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



int	get_count_nod(t_push_swap *stk)
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
