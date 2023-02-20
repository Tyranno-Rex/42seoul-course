#include "push_swap.h"

// 4. a stack에 값을 넣음
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

void	push_front(t_push_swap **stk, t_push_swap *new)
{
	if (*stk == NULL)
		*stk = new;
	else
	{
		new->next = *stk;
		*stk = new;
	}
}
