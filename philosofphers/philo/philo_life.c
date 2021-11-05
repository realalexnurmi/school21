/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:18:29 by enena             #+#    #+#             */
/*   Updated: 2021/11/04 20:40:20 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_sleeping_thinking(t_philo *philo)
{
	philo->status = sleeping;
	pthread_mutex_lock(philo->info->print);
	printf("%llu %d %s\n", timestamp(philo->info->start_time), philo->index,
		get_msg_from_type(philo->status));
	pthread_mutex_unlock(philo->info->print);
	sleep_carefully(philo->info->time_to_sleep,
		2 * philo->info->number_of_philosophers);
	philo->status = thinking;
	pthread_mutex_lock(philo->info->print);
	printf("%llu %d %s\n", timestamp(philo->info->start_time), philo->index,
		get_msg_from_type(philo->status));
	pthread_mutex_unlock(philo->info->print);
}

static void	philo_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	philo->status = take_left_fork;
	pthread_mutex_lock(philo->info->print);
	printf("%llu %d %s\n", timestamp(philo->info->start_time), philo->index,
		get_msg_from_type(philo->status));
	pthread_mutex_unlock(philo->info->print);
	pthread_mutex_lock(philo->right_fork);
	philo->status = take_right_fork;
	pthread_mutex_lock(philo->info->print);
	printf("%llu %d %s\n", timestamp(philo->info->start_time), philo->index,
		get_msg_from_type(philo->status));
	pthread_mutex_unlock(philo->info->print);
}

static void	philo_drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	philo_eating(t_philo *philo)
{
	philo_take_forks(philo);
	philo->status = eating;
	pthread_mutex_lock(philo->dead);
	pthread_mutex_lock(philo->info->print);
	printf("%llu %d %s\n", timestamp(philo->info->start_time), philo->index,
		get_msg_from_type(philo->status));
	pthread_mutex_unlock(philo->info->print);
	philo->time_last_meal = timestamp(philo->info->start_time);
	sleep_carefully(philo->info->time_to_eat,
		2 * philo->info->number_of_philosophers);
	philo_drop_forks(philo);
	if (philo->info->number_of_times_each_philo_must_eat != EMPTY)
	{
		++philo->eat_times;
		philo->is_hungry = philo->info->number_of_times_each_philo_must_eat
			> philo->eat_times;
	}
	pthread_mutex_unlock(philo->dead);
}

void	*philo_life(t_philo *philo)
{
	pthread_mutex_lock(philo->start);
	pthread_mutex_unlock(philo->start);
	while (1)
	{
		philo_eating(philo);
		philo_sleeping_thinking(philo);
	}
	return (NULL);
}
