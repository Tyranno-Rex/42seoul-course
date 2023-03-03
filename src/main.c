#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack		push_swap_a;
	t_stack		push_swap_b;
	char		**line_2d;

	// av 및 ac 점검
	if (ft_check_ac_av(ac, av))
		return (0);
	// t_stack 초기화 및 stack_a에 av 넣기
	ft_stack_init(ac, av, &push_swap_a, &push_swap_b);
	line_2d = ft_parsing_stack_a(&push_swap_a);
	ft_put_av2stack(&push_swap_a, line_2d);
	free(line_2d);
	ft_bubble_sort(&push_swap_a);
}