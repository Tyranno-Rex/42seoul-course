#include "philosopher.h"




int eating(t_philo *philo)
{
    struct timeval      time;

    if (gettimeofday(&time, NULL) != 0)
        return (1);
    if (ft_usleep(philo->data->eat_time, philo->data) != 0)
        return (1);
    if (pthread_mutex_lock(&philo->data->))
}