#include "push_swap.h"



void	set_index(t_push_swap *stack)
{
	int i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
	
}

void ft_stack_sort(t_stack *push_swap)
{
	set_index(push_swap->a);
}

int main(int ac, char **av)
{
	t_stack		*push_swap;

	push_swap = (t_stack *)malloc(sizeof(t_stack));
	// av 및 ac 점검
	if (ft_check_ac_av(ac, av))
		return (0);
	// t_stack 초기화 및 stack_a에 av 넣기
	ft_stack_init(ac, av, &push_swap);
	if (!push_swap->a)
		ft_show_error("pushing a is not done");
	ft_stack_sort(push_swap);
}