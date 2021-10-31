/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 04:27:41 by enena             #+#    #+#             */
/*   Updated: 2021/10/31 04:27:42 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		ret;

	ret = EXIT_SUCCESS;
	if (init_data(argc - 1, argv, &data) == EXIT_FAILURE)
		ret = EXIT_FAILURE;
	else if (init_philos(&data) == EXIT_FAILURE)
		ret = EXIT_FAILURE;
	else
		pthread_mutex_lock(&data.stop);
	return (ret);
}
