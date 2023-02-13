#include "push_swap.h"

int	valid_int(int val_i, char *val_c)
{
	int		res;
	char	*cr_val;

	res = 0;
	cr_val = ft_itoa(val_i);
	if (ft_strcmp(cr_val, val_c) == 0)
		res = 1;
	if (cr_val)
		free (cr_val);
	return (res);
}

int	not_dubl(t_stack *stk, int val)
{
	while (stk)
	{
		if (stk->val == val)
			return (0);
		stk = stk->next;
	}
	return (1);
}

int	sort_stacks(t_stacks *stks)
{
	t_stack	*stk_a;
	int		last_val;

	if (stks->b != NULL)
		return (0);
	stk_a = stks->a;
	last_val = stk_a->val;
	while (stk_a)
	{
		if (last_val > stk_a->val)
			return (0);
		last_val = stk_a->val;
		stk_a = stk_a->next;
	}
	return (1);
}

int	sort_stacks_check(t_stacks *stks)
{
	t_stack	*stk_a;
	int		last_val;

	stk_a = stks->a;
	last_val = stk_a->val;
	while (stk_a)
	{
		if (last_val > stk_a->val)
			return (0);
		last_val = stk_a->val;
		stk_a = stk_a->next;
	}
	return (1);
}
