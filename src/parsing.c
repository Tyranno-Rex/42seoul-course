#include "push_swap.h"


static char	*ft_static_strjoin(char *s1, char *s2)
{
	char	*result;

	if (!s1)
		s1 = ft_strdup("");
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

char **ft_parsing_stack_a(t_stack *push_swap_a)
{
	int		i;
	char	*line_av;
	char	*line_all;
	char	**line_2D;

	i = 1;
	line_all = NULL;
	while (i < push_swap_a->input.ac)
	{
        line_av = push_swap_a->input.av[i];
		line_all = ft_static_strjoin(line_all, line_av);
		line_all = ft_static_strjoin(line_all, "\n");
		line_av = NULL;
        i++;
	}
	line_2D = ft_split(line_all, '\n');
	free(line_av);
	free(line_all);
	return (line_2D);
}

void	ft_put_av2stack(t_stack *push_swap_a, char **line_2d)
{
	int array_len;
	int i;

	i = 0;
	array_len = ft_array_size(line_2d);
	push_swap_a->arr = (int *)malloc(sizeof(int) * array_len);
	while (i < array_len)
	{
		push_swap_a->arr[i] = ft_atoi(line_2d[i]);
		push_swap_a->top++;
		push_swap_a->size++;
		i++;
	}
}
