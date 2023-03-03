#include "push_swap.h"

void ft_bubble_sort(t_stack *push_swap)
{
    int i;
    int j;
    int tmp;

    i = 0;
    ft_copy_stack(push_swap);
    while (i < push_swap->size)
    {
        j = i + 1;
        while (j < push_swap->size)
        {
            if (push_swap->check_arr[j] 
                < push_swap->check_arr[i])
            {
                tmp = push_swap->check_arr[j];
                push_swap->check_arr[j] = push_swap->check_arr[i];
                push_swap->check_arr[i] = tmp;
            }
            j++;
        } 
        i++;
    }
}