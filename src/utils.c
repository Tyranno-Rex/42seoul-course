#include "push_swap.h"

void ft_show_error(char *msg)
{
    ft_printf("%s", msg);
    exit(EXIT_FAILURE);
}

void    ft_copy_stack(t_stack *push_swap)
{
    int i;

    i = 0;
    push_swap->check_arr = (int *)malloc(sizeof(int) * push_swap->size);
    if (!push_swap->check_arr)
        ft_show_error("memory isn't allocated");
    while (i < push_swap->size)
    {
        push_swap->check_arr[i] = push_swap->arr[i];
        i++;
    }
}

int		ft_array_size(char **line_2d)
{
    int i;

    i = 0;
    while (line_2d[i])
        i++;
    return (i);
}

int	ft_atoi_pro(const char *the_char)
{
	int			i;
	int			sign;
	long long	n;

	i = 0;
	sign = 1;
	n = 0;
	while (the_char[i] == ' ' || the_char[i] == '\n' || the_char[i] == '\t' || \
			the_char[i] == '\v' || the_char[i] == '\f' || the_char[i] == '\r')
		i++;
	if (the_char[i] == '-')
		sign *= -1;
	if (the_char[i] == '-' || the_char[i] == '+')
		i++;
	while (the_char[i] && the_char[i] >= '0' && the_char[i] <= '9')
	{
		n = n * 10 + (the_char[i] - '0');
		i++;
	}
	if (n * sign > 2147483647)
		ft_show_error("input number exceeded int range.\n");
	else if (n * sign < -2147483648)
		ft_show_error("input number exceeded int range.\n");
	return (n * sign);
}
