#include "push_swap.h"

void ft_stack_init(int ac, char **av, t_stack *push_swap_a, t_stack *push_swap_b)
{
    push_swap_a->input.ac = ac;
    push_swap_a->input.av = av;
    push_swap_a->arr = NULL;
    push_swap_a->line = NULL;
    push_swap_a->check_arr = NULL;
    push_swap_a->size = 0;
    push_swap_a->top = -1;

    push_swap_b->arr = NULL;
    push_swap_b->line = NULL;
    push_swap_b->check_arr = NULL;
    push_swap_b->size = 0;
    push_swap_b->top = -1;
}