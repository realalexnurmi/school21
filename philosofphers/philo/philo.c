#include "philo.h"

int main(int argc, char **argv)
{
    t_data      data;
    signed char ret;

    ret = EXIT_SUCCESS;
    if (!get_options(argc - 1, argv, &data))
        ret = EXIT_FAILURE;
    else if (!init_data(&data))
        ret = EXIT_FAILURE;
    else if (!init_philos(&data))
        ret = EXIT_FAILURE;
    else
        pthread_mutex_lock(&data.stop);
    return (ret);
}