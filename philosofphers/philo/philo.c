/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 04:27:41 by enena             #+#    #+#             */
/*   Updated: 2021/11/04 22:10:27 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_is_alive(t_philo *philo)
{
	int	ret;

	ret = TRUE;
	if ((philo->status != eating))
	{
		pthread_mutex_lock(philo->dead);
		ret = ((timestamp(philo->info->start_time) - philo->time_last_meal)
				<= (t_ms)philo->info->time_to_die);
		pthread_mutex_unlock(philo->dead);
	}
	return (ret);
}

static int	nobody_dead(t_data *data)
{
	int	ret;
	int	i;

	ret = TRUE;
	i = PRESTART;
	while (ret && ++i < data->info->number_of_philosophers)
		ret &= philo_is_alive(&data->philos[i]);
	if (!ret)
	{
		pthread_mutex_lock(data->info->print);
		printf("%llu philo %d died\n",
			timestamp(data->info->start_time), i + 1);
	}
	return (ret);
}

static int	someone_hungry(t_data *data)
{
	int	ret;
	int	i;

	ret = TRUE;
	if (data->info->number_of_times_each_philo_must_eat != EMPTY)
	{
		i = PRESTART;
		ret = FALSE;
		while ((!ret) && ++i < data->info->number_of_philosophers)
			ret |= data->philos[i].is_hungry;
	}
	return (ret);
}

static void	sit_down_please(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_unlock(data->info->odd);
	while (i < data->info->number_of_philosophers - 1)
	{
		if (data->philos[i].status == eating)
			i += 2;
	}
	pthread_mutex_unlock(data->info->last_odd);
	pthread_mutex_unlock(data->info->even);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		ret;

	ret = EXIT_SUCCESS;
	if (init_info((argc - 1), argv, &data) == EXIT_FAILURE)
		ret = EXIT_FAILURE;
	else if (init_philos(&data) == EXIT_FAILURE)
		ret = EXIT_FAILURE;
	else
	{
		data.info->start_time = get_current_ms();
		sit_down_please(&data);
		while (nobody_dead(&data) && someone_hungry(&data))
			;
		thank_you_for_visiting_my_restaurant_but_now_die_everyone(&data);
	}
	return (ret);
}
