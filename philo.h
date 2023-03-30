#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_env	t_env;

typedef struct s_philo
{
	int				id;
	int				num_of_eat;
	t_env			*env;
	pthread_t		thread;
	struct timeval	meal_time;
}				t_philo;

struct s_env
{
	t_philo			*ph;
	struct timeval	start;

	int				life_flag;
	int				check_dead;
	int				philo_number;
	int				when_die;
	int				when_eat;
	int				when_sleep;
	int				num_of_eat;

	pthread_mutex_t	m_alive;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*mutex_eat_time;
	pthread_mutex_t	*mutex_nb_eat;
};


/*CHECK_ARGV*/
int		ft_check_env(t_env *env);
int		ft_init_env(int ac, char **av, t_env *env);

/*INIT_MUTEX.C*/
int		take_a_fork(t_env *env, int n, int fork);
int		ft_init_forks(t_env *env);
int		ft_init_mutex_meal_time(t_env *env);

/*INIT_THREAD.C*/
int		ft_init_meal_time(t_env *env);
int		ft_init_thread(t_env *env);
int		check_alive(t_env *env);

/*LAUNCH_THREAD.C*/
int		eating(t_philo *ph);
int		sleeping(t_philo *ph);
int		thinking(t_philo *ph);
int		ft_manage_forks(t_philo *ph);
void	*launch_thread(void *arg);

/*LAUNCH_WAITER.C*/
void	*launch_waiter(t_env *env);
int		check_time_last_meal(t_env *env, int i, int *ret);

/*PHILO_UTILS.C*/
int		ft_atoi(const char *the_char);
void	ft_free(t_env *env);
long	get_time_in_ms(struct timeval time);
int		ft_usleep(long time, t_env *env);
int		ft_join_thread(t_env *env);
int		print_result(long elapsed_time, int philo, char *msg);

/* PHILO_UTILS.C*/
int		ft_print_error(char *error, int retur);

#endif