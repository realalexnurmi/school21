/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tyfvmrbnde.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:53:48 by enena             #+#    #+#             */
/*   Updated: 2021/11/04 21:58:31 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thank_you_for_visiting_my_restaurant_but_now_die_everyone(t_data *data)
{
	int	i;

	i = PRESTART;
	while (++i < data->info->number_of_philosophers)
	{
		pthread_mutex_destroy(data->philos[i].dead);
		free(data->philos[i].dead);
		pthread_mutex_destroy(data->philos[i].left_fork);
		free(data->philos[i].left_fork);
	}
	free(data->philos);
	pthread_mutex_destroy(data->info->print);
	free(data->info->print);
	pthread_mutex_destroy(data->info->even);
	free(data->info->even);
	pthread_mutex_destroy(data->info->odd);
	free(data->info->odd);
	pthread_mutex_destroy(data->info->last_odd);
	free(data->info->last_odd);
	free(data->info);
}
