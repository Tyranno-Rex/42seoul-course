#include "push_swap.h"

void run(t_stack *stack_a, t_stack *stack_b, int argc_len)
{
	if (argc_len >= 2 && argc_len <= 5)
		hard_case(&stack_a, &stack_b, argc_len);
	else
		radix_algo(&stack_a, &stack_b, argc_len);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**str_2D;
	char	*str_char;
	int		*str_int;

	stack_a = NULL;
	stack_b = NULL;
	check_ac_av(argc, argv);
	str_char = parsing_argv(argc, argv);
	str_2D = ft_split(str_char, ' ');
	str_int = put_tab_int(argc - 1, str_2D);
	check_dup(argc - 1, str_int);
	create_stack_a(&stack_a, argc - 1, str_int);
	check_order(stack_a);
	run(stack_a, stack_b, argc - 1);
	free_lst(&stack_a);
	free_lst(&stack_b);
	return (0);
}
