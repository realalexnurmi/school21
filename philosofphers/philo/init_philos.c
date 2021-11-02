/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 04:27:54 by enena             #+#    #+#             */
/*   Updated: 2021/11/02 05:06:09 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_setup(t_data *data, t_philo *philo, int index)
{
	int ret;

	ret = EXIT_SUCCESS;
	philo->index = index;
	philo->is_alive = TRUE;
	philo->is_hungry = TRUE;
	philo->left_to_eat = data->opt.number_of_times_each_philo_must_eat;
	philo->start = &data->start;
	philo->buffer_msg = NULL;
	if (pthread_create(&philo->thread, NULL,
		(void *)&philo_life, philo) != EXIT_SUCCESS)
	{
		ret = EXIT_FAILURE;
	}
	return (ret);
}

int	init_philos(t_data *data)
{
	int	ret;
	int i;

	ret = EXIT_SUCCESS;
	printf("Creation\n");
	data->philos = malloc(data->opt.number_of_philosophers * sizeof(t_philo));
	if (!data->philos)
		ret = EXIT_FAILURE;
	else
	{
		i = -1;
		while (++i < data->opt.number_of_philosophers)
		{
			if (philo_setup(data, &data->philos[i], i) == EXIT_FAILURE)
			{
				ret = EXIT_FAILURE;
				break ;
			}
			pthread_detach(data->philos[i].thread);
			printf("%d\n", i);
		}
	}
	printf("All good\n");
	return (ret);
}

void	*philo_life(t_philo *philo)
{
	pthread_mutex_lock(philo->start);
	pthread_mutex_unlock(philo->start);
	philo->start_time = get_current_ms();
	printf("Philo %d born %llu ms\n", philo->index, philo->start_time);
	return (NULL);
}
