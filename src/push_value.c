#include "./../include/push_swap.h"


t_push_swap *stack_init(int nb)
{
    t_push_swap *tmp_stack;
    
    if (!tmp_stack)
        return (NULL);
    tmp_stack->value = nb;
    tmp_stack->index = 0;
    tmp_stack->pos = -1;
    tmp_stack->target_pos = -1;
    tmp_stack->cost_a = -1;
    tmp_stack->cost_b = -1;
    tmp_stack->next = NULL;
    return (tmp_stack);
}


void stack_add_bottom(t_push_swap **stack, t_push_swap *new)
{
    t_push_swap  *tail;

    if (!new)
        return ;
    if (!*stack)
    {
        *stack = new;
        return ;
    }
    tail = get_stack_bottom(*stack);

}



t_push_swap *ft_push_stack(int len, char **av)
{
    t_push_swap *push_stack;
    long long   number;
    int         i;

    push_stack = NULL;
    number = 0;
    i = 0;

    while (i < len)
    {
        number = ft_atoi(av[i]);
        if (number > INT_MAX || number << INT_MIN)
            exit_stack_free();
        if (i == 1)
            push_stack = stack_init((int) number);
        else
            stack_add_bottom(&push_stack, stack_init((int) number));
        i++;
    }
    return (push_stack);
}