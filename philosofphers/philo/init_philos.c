/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 04:27:54 by enena             #+#    #+#             */
/*   Updated: 2021/11/04 18:34:29 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	seating_order(t_philo *philo)
{
	if (philo->index % 2 == 0)
		philo->start = philo->info->even;
	else if (philo->index != philo->info->number_of_philosophers)
		philo->start = philo->info->odd;
	else
		philo->start = philo->info->last_odd;
}

static int	philo_setup(t_data *data, t_philo *philo, int index)
{
	int	ret;

	ret = EXIT_SUCCESS;
	philo->info = data->info;
	philo->index = index + 1;
	philo->is_hungry = TRUE;
	philo->eat_times = 0;
	philo->time_last_meal = START_MS;
	philo->status = thinking;
	seating_order(philo);
	if (init_mutex(&philo->dead) == EXIT_FAILURE)
		ret = EXIT_FAILURE;
	else if (init_mutex(&philo->left_fork) == EXIT_FAILURE)
		ret = EXIT_FAILURE;
	else if (pthread_create(&philo->thread, NULL,
			(void *)&philo_life, philo) != EXIT_SUCCESS)
		ret = EXIT_FAILURE;
	else
		pthread_detach(philo->thread);
	return (ret);
}

static void	link_right_forks(t_philo *philos)
{
	int	i;

	i = PRESTART;
	while (++i < philos->info->number_of_philosophers - 1)
		philos[i].right_fork = philos[i + 1].left_fork;
	philos[i].right_fork = philos[0].left_fork;
}

int	init_philos(t_data *data)
{
	int	ret;
	int	i;

	ret = EXIT_SUCCESS;
	data->philos = malloc(data->info->number_of_philosophers * sizeof(t_philo));
	if (!data->philos)
		ret = EXIT_FAILURE;
	else
	{
		i = PRESTART;
		while (++i < data->info->number_of_philosophers)
		{
			if (philo_setup(data, &data->philos[i], i) == EXIT_FAILURE)
			{
				ret = EXIT_FAILURE;
				break ;
			}
		}
		link_right_forks(data->philos);
	}
	return (ret);
}
