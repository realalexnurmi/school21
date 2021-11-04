/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 04:27:58 by enena             #+#    #+#             */
/*   Updated: 2021/11/04 18:19:47 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	orders_mutex_init(t_data *data)
{
	int	ret;

	ret = EXIT_SUCCESS;
	if (init_mutex(&data->info->even) == EXIT_FAILURE)
		ret = EXIT_FAILURE;
	else if (init_mutex(&data->info->odd) == EXIT_FAILURE)
		ret = EXIT_FAILURE;
	else if (init_mutex(&data->info->last_odd) == EXIT_FAILURE)
		ret = EXIT_FAILURE;
	else
	{
		pthread_mutex_lock(data->info->even);
		pthread_mutex_lock(data->info->odd);
		pthread_mutex_lock(data->info->last_odd);
	}
	return (ret);
}

int	init_info(int count_options, char **value_options, t_data *data)
{
	int	ret;

	ret = EXIT_SUCCESS;
	data->info = malloc(sizeof(t_info));
	if (!data->info)
		ret = EXIT_FAILURE;
	else if (get_options(count_options, value_options,
			data->info) == EXIT_FAILURE)
		ret = EXIT_FAILURE;
	else if (orders_mutex_init(data) == EXIT_FAILURE)
		ret = EXIT_FAILURE;
	else if (init_mutex(&data->info->print) == EXIT_FAILURE)
		ret = EXIT_FAILURE;
	return (ret);
}
