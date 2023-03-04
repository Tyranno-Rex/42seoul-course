#include "../push_swap.h"

void show_error(char *msg)
{
	write(1, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void show_free_error(char *msg, char *target)
{
	write(1, msg, ft_strlen(msg));
	free(target);
	exit(EXIT_FAILURE);
}

void show_free_error_2(char *msg, int *target)
{
	write(1, msg, ft_strlen(msg));
	free(target);
	exit(EXIT_FAILURE);
}

int	*put_tab_int(int nbr_arg, char **tab_str)
{
	int	*temp_tab;
	int	i;

	temp_tab = malloc(sizeof(int) * nbr_arg);
	if (!temp_tab)
		return (NULL);
	i = 0;
	while (tab_str[i])
	{
		temp_tab[i] = ft_atoi(tab_str[i]);
		if (temp_tab[i] == 0)
		{
			if (check_atoi(tab_str[i], ft_atoi(tab_str[i])) == 1)
			{
				free_2D(tab_str);
				show_free_error_2("Error\n", temp_tab);
			}
		}
		i++;
	}
	free_2D(tab_str);
	return (temp_tab);
}