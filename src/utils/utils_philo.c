#include "philo.h"
time_t get_time(void);
void waiting(t_data *data, time_t waiting_time);
int exit_condition(t_data *data);
int dead_condition(t_philo *philo);

time_t get_time(void)
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void waiting(t_data *data, time_t waiting_time)
{
    time_t wake_time;

    wake_time = get_time() + waiting_time;
    while(get_time() < wake_time)
    {
        if(exit_condition(data))
            break;
        usleep(100);
    }
}

int exit_condition(t_data *data)
{
    int status;

    status = 0;
    pthread_mutex_lock(&data->lock_exit);
    if(data->is_exit == 1)
    status = 1;
    pthread_mutex_unlock(&data->lock_exit);
    return (status);
}

int dead_condition(t_philo *philo)
{
    pthread_mutex_lock(&philo->lock_eat_routine);
    if(get_time() - philo->last_meal >= philo->data->death_time)
    {
        print_action(philo, DIED);
        pthread_mutex_lock(&philo->data->lock_exit);
        philo->data->is_exit = 1;
        pthread_mutex_unlock(&philo->data->lock_exit);
        pthread_mutex_unlock(&philo->lock_eat_routine);
        return (1);
    }
    pthread_mutex_unlock(&philo->lock_eat_routine);
    return (0);
}