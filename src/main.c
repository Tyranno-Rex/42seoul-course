
#include "./../include/push_swap.h"

// 부호인지 확인한다. 만약 부호가 아닌 그냥 숫자가 올 수도 있으니 이에 대한 예외처리도 진행한다.
int ft_check_is_sign(char c)
{
	if (c == '-' || c == '+') 
		return (0);
	else
		if (c >= 48 && c <= 57)
			return (0);
		return (1);
}

// 개별적으로 분해된 문자열이 전부 숫자로 이루어져있는지 확인한다.
int	ft_check_is_number(char *num)
{
	int i;
	
	i = 1;
	// 처음에 오는 숫자가 부호인지 확인한다. 그리고 두번째 오는 문자가 널문자이면 안된다.
	if (ft_check_is_sign(num[0]) && num[1] != '\0')
	{
		ft_printf("you in put wrong");
		return (1);	
	}
	// while 문을 돌리면서 문자를 확인한다.
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
		{
			ft_printf("you input wrong number.\nnumber must be consist of only number");
			return (1);
		}
		i++;
	}
	return (0);
}

// ac와 av의 체크를 진행함.
// ac의 체크는 바로 진행하되, av의 진행은 문자열 각각을 톨리고, 문자열 개별의 세부적인 체크는 함수에 넘겨서 진행한다.
int	ft_check_ac_av(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 2)
	{
		ft_printf("ac is must more than 2");
		return (1);
	}
	// 문자열 전부다 돌리고 개별은 함수로 넘긴다.
	while (av[i])
	{
		if (ft_check_is_number(av[i]))
		{
			ft_printf("you are argv value is wrong");
			return (1);
		}
		i++;
	}
	// false를 반환하면 프로그램을 진행한다.
	return (0);
}

int main(int ac, char **av)
{
    int			stack_len;
    t_push_swap *stack_a;
    t_push_swap *stack_b;

	// 숫자의 값이 잘못 됨 -> stack의 초기화를 진행해야함.
	stack_len = ac - 1;
	if (ft_check_ac_av(ac, av))
		return (0);
	stack_b = NULL;
	stack_a = ft_push_stack(stack_len, av);
}