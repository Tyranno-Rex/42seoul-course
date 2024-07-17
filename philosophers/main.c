#include "philo.h"

// void	check_leak(void)
// {
// 	system("leaks --list -- philo");
// }

int	main(int ac, char **av)
{
	t_env		env;

	// atexit(check_leak);
	if (gettimeofday(&env.start, NULL) != 0)
		return (ft_print_error("FIRST GET_TIME_OF_DAY_FAILED", -1));
	if (ac != 5 && ac != 6)
		return (ft_print_error("NOT ENOUGH OR TOO MANY ARGUMENTS", -1));
	if (ft_init_env(ac, av, &env) || ft_check_env(&env) || ft_init_forks(&env))
		return (1);
	if (ft_init_thread(&env))
		return (1);
	ft_free(&env);
	return (0);
}
