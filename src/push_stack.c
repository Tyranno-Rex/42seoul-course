#include "./../include/push_swap.h"

t_push_swap *ft_push_add_bottom(int value)
{
    t_push_swap *tmp;

    tmp = (t_push_swap *)malloc(sizeof(t_push_swap));
    tmp->index = 0;
    tmp->sort = 1;
    tmp->value = value;
    tmp->next = NULL;
    return (tmp);
}