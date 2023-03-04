#include "../push_swap.h"

void	hard_case(t_stack **stack_a, t_stack **stack_b, int nbr_arg)
{
	(void)stack_b;
	if (nbr_arg == 2)
		sort_two(stack_a);
	else if (nbr_arg == 3)
		sort_three(stack_a);
	else if (nbr_arg == 4)
		sort_four(stack_a, stack_b);
	else if (nbr_arg == 5)
		sort_five(stack_a, stack_b);
	return ;
}

void	sort_two(t_stack **stack_a)
{
	move_swap(stack_a, 'a');
	return ;
}

void	sort_three(t_stack **stack_a)
{
	if ((*stack_a)->value - 1 == (*stack_a)->next->value
		|| (*stack_a)->value + 2 == (*stack_a)->next->value)
		move_swap(stack_a, 'a');
	if ((*stack_a)->value + 1 == (*stack_a)->next->value
		&& (*stack_a)->next->next->value + 1 == (*stack_a)->value)
		move_rev_rotate(stack_a, 'a');
	else if ((*stack_a)->value - 2 == (*stack_a)->next->value)
		move_rotate(stack_a, 'a');
	return ;
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	while (!(*stack_b))
	{
		if ((*stack_a)->value == 0)
			move_push(stack_a, stack_b, 'b');
		else
			move_rotate(stack_a, 'a');
	}
	sort_three(stack_a);
	move_push(stack_b, stack_a, 'a');
	return ;
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	while (!(*stack_b) || !(*stack_b)->next)
	{
		if ((*stack_a)->value == 0 || (*stack_a)->value == 1)
			move_push(stack_a, stack_b, 'b');
		else
			move_rotate(stack_a, 'a');
	}
	sort_three(stack_a);
	if ((*stack_b)->value == 0)
		move_swap(stack_b, 'b');
	move_push(stack_b, stack_a, 'a');
	move_push(stack_b, stack_a, 'a');
	return ;
}
