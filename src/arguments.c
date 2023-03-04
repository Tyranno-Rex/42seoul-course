#include "../push_swap.h"

char	*parsing_argv(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 0;
	if (argc == 1)
		exit(1);
	str = malloc(sizeof(char) * (arguments_len(argv)));
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (++i != argc)
	{
		if (argv[i][0] == '\0')
			show_free_error("error", str);
		str = ft_strjoin(str, argv[i]);
	}
	return (str);
}

int	arguments_len(char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	j = 0;
	len = 0;
	while (argv[i])
	{
		while (argv[i][j] != '\0')
		{
			len++;
			j++;
		}
		i++;
		j = 0;
	}
	return (len);
}
