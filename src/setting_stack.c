#include "./../include/push_swap.h"

t_push_swap *get_stack_bottom(t_push_swap *tmp)
{
    while (tmp && tmp->next != NULL)
        tmp = tmp->next;
    return (tmp);
}

