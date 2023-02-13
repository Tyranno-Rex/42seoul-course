#include "./../include/push_swap.h"

int main(int ac, char **av)
{
    int			stack_len;
	t_stack		*push_swap;

	push_swap = (t_stack *)malloc(sizeof(t_stack));

	// 숫자의 값이 잘못 됨 -> stack의 초기화를 진행해야함.
	stack_len = ac - 1;
	if (ft_check_ac_av(ac, av))
		return (0);
	push_swap = ft_push_swap_init(stack_len, av, push_swap);
}