#include "philo.h"

int	ft_check_env(t_env *env)
{
	if (env->philo_number < 0 || env->when_die < 0
		|| env->when_sleep < 0 || env->when_eat < 0)
		return (print_error("INVALID ARGUMENTS", -1));
	if (env->philo_number == 0 || env->num_of_eat == 0)
		return (print_error(NULL, -1));
	return (0);
}

int	ft_init_env(int ac, char **av, t_env *env)
{
	int	i;
	int	j;

	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if (av[j][i] < '0' || av[j][i] > '9')
				return (print_error("ARGUMENT AREN'T NUMBER", -1));
			i++;
		}
		j++;
	}
	env->philo_number = ft_atoi(av[1]);
	env->when_die = ft_atoi(av[2]);
	env->when_eat = ft_atoi(av[3]);
	env->when_sleep = ft_atoi(av[4]);
	env->num_of_eat = 2147483647;
	if (ac == 6)
		env->num_of_eat = ft_atoi(av[5]);
	env->life_flag = 0;
	return (0);
}

// void	check_leak(void)
// {
// 	system("leaks --list -- philo");
// }

int	main(int ac, char **av)
{
	t_env		env;
	// char 		*ma = malloc(100000);

	// ma[1] = 'h';
	// atexit(check_leak);
	if (gettimeofday(&env.start, NULL) != 0)
		return (print_error("FIRST GET_TIME_OF_DAY_FAILED", -1));
	if (ac != 5 && ac != 6)
		return (print_error("NOT ENOUGH OR TOO MANY ARGUMENTS", -1));
	if (ft_init_env(ac, av, &env) || ft_check_env(&env) || ft_init_forks(&env))
		return (1);
	if (ft_init_thread(&env))
		return (1);
	ft_free(&env);
	return (0);
}
