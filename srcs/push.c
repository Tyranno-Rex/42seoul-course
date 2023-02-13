#include "push_swap.h"

// 4. a stack에 값을 넣음
void	push_back(t_stack **stk, t_stack *new)
{
	t_stack	*last;

	if (*stk == NULL)
	{
		*stk = new;
		return ;
	}
	last = get_last_nod(*stk);
	last->next = new;
}

void	push_front(t_stack **stk, t_stack *new)
{
	if (*stk == NULL)
		*stk = new;
	else
	{
		new->next = *stk;
		*stk = new;
	}
}

// 2. a stack에 값을 넣음
t_stack	*push_back_int(t_stack **stk, int val)
{
	t_stack	*new;

	new = create_new_nod(val);
	if (new == NULL)
		return (NULL);
	push_back(stk, new);
	return (*stk);
}
