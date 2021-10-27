#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0

typedef struct s_options
{
    signed int	number_of_philosophers;
    signed int	time_to_die;
    signed int	time_to_eat;
    signed int	time_to_sleep;
    signed int	number_of_times_each_philo_must_eat;
}   t_options;

typedef unsigned long long int  t_ms;

typedef struct s_philo
{
    pthread_t       thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    signed int      left_to_eat;
}   t_philo;


typedef struct s_data
{
    t_options       options;
    pthread_mutex_t start;
    pthread_mutex_t stop;
    t_philo         *philos;
}   t_data;


#endif