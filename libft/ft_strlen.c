int	ft_strlen(char *str)
{
	int		the_num;

	the_num = 0;
	while (*str != '\0')
	{
		the_num++;
		str++;
	}
	return (the_num);
}
