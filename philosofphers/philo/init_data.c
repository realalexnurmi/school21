/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 04:27:58 by enena             #+#    #+#             */
/*   Updated: 2021/11/02 00:43:32 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(int count_options, char **value_options, t_data *data)
{
	int	ret;

	ret = EXIT_SUCCESS;
	if (get_options(count_options, value_options, data) == EXIT_FAILURE)
		ret = EXIT_FAILURE;
	else if (pthread_mutex_init(&data->start, NULL) != EXIT_SUCCESS)
		ret = EXIT_FAILURE;
	else
		pthread_mutex_lock(&data->start);
	return (ret);
}