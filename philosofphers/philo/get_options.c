#include "philo.h"

int get_options(int count_options, char **value_options, t_data *data)
{
    int ret;

    ret = EXIT_SUCCESS;
    if (count_options < 4 || count_options > 5)
        ret = EXIT_FAILURE;
    else
    {
        data->options.number_of_philosophers = 1;
        data->options.time_to_die = 2;
        data->options.time_to_eat = 3;
        data->options.time_to_sleep = 4;
        
    }
    return(ret);
}