#include "push_swap.h"

void ft_show_error(char *msg)
{
    ft_printf("%s", msg);
    exit(EXIT_FAILURE);
}

void    copy_stack(t_stack *push_swap)
{
    int i;

    i = 0;
    push_swap->check_arr = (int *)malloc(sizeof(int) * push_swap->size);
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