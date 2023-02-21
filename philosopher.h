#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_data
{
    int philo_num;
    int philo_span;
    int philo_eat;
    int philo_sleep;
    int philo_clear;
}   t_data;


/*utils.c*/
int			ft_atoi(const char *the_char);
int			ft_isdigit(int c);
void		ft_showe_error(char *msg);

/*struct_inti.c*/
void        ft_can_clear(int ac, char **av, t_data *data);
void        ft_cant_clear(int ac, char **av, t_data *data);

/*check.c*/
void        ft_check_ac_av(int ac, char **av, t_data *data, pthread_mutex_t fork);