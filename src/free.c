#include "../push_swap.h"

void	free_lst(t_stack **stack)
{
	if ((*stack) != NULL)
	{
		free_lst(&(*stack)->next);
		free((*stack));
	}
}

void	free_2D(char **tab_str)
{
	int	i;

	i = 0;
	while (tab_str[i])
	{
		free(tab_str[i]);
		i++;
	}
	free(tab_str);
}
