#include "../push_swap.h"

void	check_order(t_stack *stack)
{
	t_stack	*tmp_head;

	tmp_head = stack;
	while (stack->next != NULL)
	{
		if (stack->value < stack->next->value)
			stack = stack->next;
		else
			return ;
	}
	stack = tmp_head;
	free_lst(&stack);
	exit(EXIT_SUCCESS);
}

int	get_index(int num, int *tab, int nb)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	while (j < num)
	{
		if (nb > tab[j])
			index++;
		j++;
	}
	return (index);
}

void	create_stack_a(t_stack **stack_a, int num, int *str_int)
{
	int		i;

	i = 0;
	while (i < num)
	{
		create_node(stack_a, get_index(num, str_int, str_int[i]));
		i++;
	}
	free(str_int);
	return ;
}

void	create_node(t_stack **head, int index)
{
	t_stack	*new;
	t_stack	*tmp;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->value = index;
	if (!*head)
	{
		*head = new;
		(*head)->next = NULL;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

