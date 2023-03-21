#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct s_data t_data;

typedef struct s_philo
{
    int                 name;
    struct timeval      when_eat;
    int                 what_eat;

    pthread_t           thread;
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
    
    t_philo             *philo;

    pthread_mutex_t     *fork;
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