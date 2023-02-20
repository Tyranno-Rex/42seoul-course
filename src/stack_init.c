#include "push_swap.h"

t_push_swap *ft_new_node_init(int number)
{
	t_push_swap *new;

	new = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (new == NULL)
		return (NULL);
	new->value = number;
	new->index = 0;
	new->sort = 1;
	new->next= NULL;
	return (new);
}

void push_back(t_push_swap **push_swap, t_push_swap *tmp)
{
	t_push_swap *last;

	if (*push_swap == NULL)
	{
		*push_swap = tmp;
		return;
	}
	last = *push_swap;
	while (last->next)
		last = last->next;
	last->next = tmp;
}


t_push_swap *ft_push_value(t_push_swap **push_swap, int number)
{
	t_push_swap *new;

	new = ft_new_node_init(number);
	if (new == NULL)
		return (NULL);
	push_back(push_swap, new);
	return (push_swap);
}

static void ft_stack_a_init(t_stack *push_swap, int ac, char **av)
{
	int i;
	int number;

	i = 1;
	while (i < ac)
	{
		number = ft_atoi(av[i]);
		if (ft_push_value(&push_swap->a, number) == NULL)
			ft_show_error("");
		i++;
	}
	return ;
}

void ft_stack_init(int ac, char **av, t_stack *push_swap)
{
	push_swap = (t_stack *)malloc(sizeof(t_stack));
	if (!push_swap)
		ft_show_error("push swap memory allocation error");
	push_swap->a = NULL;
	push_swap->b = NULL;
	push_swap->cmd_cnt = 0;
	ft_stack_a_init(push_swap, ac, av);
}