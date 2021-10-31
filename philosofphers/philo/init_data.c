/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 04:27:58 by enena             #+#    #+#             */
/*   Updated: 2021/10/31 04:28:00 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(int count_options, char **value_options, t_data *data)
{
	int	ret;

	ret = EXIT_SUCCESS;
	if (get_options(count_options, value_options, data) == EXIT_FAILURE)
		ret = EXIT_FAILURE;
	else if (pthread_mutex_init(&data->start, NULL) != EXIT_SUCCESS
		|| pthread_mutex_init(&data->stop, NULL) != EXIT_SUCCESS)
		ret = EXIT_FAILURE;
	else
	{
		data->start_time = get_current_ms();
		pthread_mutex_lock(&data->start);
		pthread_mutex_lock(&data->stop);
	}
	return (ret);
}