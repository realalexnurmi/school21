/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 04:27:45 by enena             #+#    #+#             */
/*   Updated: 2021/10/31 04:27:46 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ms	get_current_ms(void)
{
	struct timeval time_of_day;

	gettimeofday(&time_of_day, NULL);
	return (time_of_day.tv_sec * 1000 + time_of_day.tv_usec / 1000);
}