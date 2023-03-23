


#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include <string.h>



typedef struct s_data t_data;

typedef struct s_philo
{
    struct timeval      when_eat;
    int                 name;
    int                 how_many_eat;
    pthread_t           thread;

    t_data              *data;
}   t_philo;

/*전체 데이터 구조체*/
/*
1. 게임 시작 시간 데이터
2. 총 철학자 수
3. 밥을 안먹고 버틸 수 있는 시간
4. 밥 먹는 시간

*/
typedef struct s_data
{
    struct timeval      game_start;
    int                 total_philo;
    int                 dead_time;
    int                 eat_time;
    int                 sleep_time;
    int                 life_flag;
    int                 alive;
    int                 check_dead;
    int                 goal_of_eat;
    
    pthread_mutex_t     *eat_time;
    pthread_mutex_t     alive_mutex;
    pthread_mutex_t     *fork;
    
    t_philo             *philo;
}   t_data;


/*utils.c*/
int			ft_atoi(const char *the_char);
int			ft_isdigit(char c);
void		ft_showe_error(char *msg);

/*struct_inti.c*/
void        ft_can_clear(int ac, char **av, t_data *data);
void        ft_cant_clear(int ac, char **av, t_data *data);

/*check.c*/
void        ft_check_ac_av(int ac, char **av);