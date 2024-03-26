#include "push_swap.h"

void    atoi_pro(const char *the_char)
{
	int			i;
	int			sign;
	long long	n;

	i = 0;
	sign = 1;
	n = 0;
	while (the_char[i] == ' ' || the_char[i] == '\n' || the_char[i] == '\t' || \
			the_char[i] == '\v' || the_char[i] == '\f' || the_char[i] == '\r')
		i++;
	if (the_char[i] == '-')
		sign *= -1;
	if (the_char[i] == '-' || the_char[i] == '+')
		i++;
	while (the_char[i] && the_char[i] >= '0' && the_char[i] <= '9')
	{
		n = n * 10 + (the_char[i] - '0');
		i++;
	}
	if (n * sign > 2147483647)
        show_error("Error\n");
    else if (n * sign < -2147483648)
        show_error("Error\n");
}

void	verif_args(char *argv)
{
	int	i;
	int	is_sign;

	i = 0;
	is_sign = 1;
	while (argv[i] != '\0')
	{
		if ((argv[i] == '+' || argv[i] == '-') && argv[i - 1] != ' ' && i != 0)
            show_error("Error\n");
		if ((argv[i] == '+' || argv[i] == '-') && ft_isdigit(argv[i + 1]) == 0)
            show_error("Error\n");
		if (ft_isdigit(argv[i]) == 1 || argv[i] == ' ')
			is_sign = 0;
		else if ((argv[i] == '+' || argv[i] == '-') && is_sign < 2)
			is_sign += 1;
        else
            show_error("Error\n");
		i++;
	}
}

int	space_only(char *argv)
{
	int		i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	check_ac_av(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			exit(EXIT_FAILURE);
		i++;
	}
	i = 1;
	while (i < argc)
	{
		if (space_only(argv[i]) == 1)
			exit(EXIT_FAILURE);
		verif_args(argv[i]);
        atoi_pro(argv[i]);
        i++;
	}
}