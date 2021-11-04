/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 04:27:45 by enena             #+#    #+#             */
/*   Updated: 2021/11/04 18:48:14 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ms	get_current_ms(void)
{
	struct timeval	time_of_day;

	gettimeofday(&time_of_day, NULL);
	return (time_of_day.tv_sec * 1000 + time_of_day.tv_usec / 1000);
}

void	sleep_carefully(t_ms time_to_sleep, t_ms part_sleep)
{
	t_ms	stop;

	stop = get_current_ms() + time_to_sleep;
	while (get_current_ms() < stop)
		usleep (part_sleep);
}

t_ms	timestamp(t_ms start)
{
	return (get_current_ms() - start);
}
