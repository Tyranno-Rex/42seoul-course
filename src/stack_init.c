#include "./../include/push_swap.h"



static void ft_setting_a(int len, char **av, t_stack *push_swap)
{
    int i;
    int value;

    i = 0;
    while (i < len - 1)
    {
        value = ft_atoi(av[i]);
        if (ft_push_add_bottom(&push_swap->a, value) == NULL)
        {
            ft_printf("error");
            exit(EXIT_FAILURE);
        }
        i++;
    }
}


t_stack *ft_push_swap_init(int len, char **av, t_stack *push_swap)
{
    push_swap->a = NULL;
    push_swap->b = NULL;
    push_swap->a_len = 0;
    push_swap->b_len = 0;
    ft_setting_a(len, av, push_swap);
    return (push_swap);
}