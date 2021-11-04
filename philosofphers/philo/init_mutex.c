/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 04:28:09 by enena             #+#    #+#             */
/*   Updated: 2021/11/04 15:41:47 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(pthread_mutex_t	**mutex)
{
	int	ret;

	ret = EXIT_SUCCESS;
	*mutex = malloc(sizeof(pthread_mutex_t));
	if (!(*mutex))
		ret = EXIT_FAILURE;
	else if (pthread_mutex_init(*mutex, NULL) != EXIT_SUCCESS)
	{
		free(*mutex);
		*mutex = NULL;
		ret = EXIT_FAILURE;
	}
	return (ret);
}
