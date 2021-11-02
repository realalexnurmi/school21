/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 04:27:41 by enena             #+#    #+#             */
/*   Updated: 2021/11/02 07:17:46 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	nobody_dead(t_data *data)
{
	int	ret;
	int	i;

	ret = TRUE;
	i = PRESTART;
	while (ret && ++i < data->opt.number_of_philosophers)
		ret &= data->philos[i].is_alive;
	return (ret);
}

static int	someone_hungry(t_data *data)
{
	int	ret;
	int	i;

	ret = TRUE;
	if (data->opt.number_of_times_each_philo_must_eat != -1)
	{
		i = PRESTART;
		ret = FALSE;
		while (ret && ++i < data->opt.number_of_philosophers)
			ret |= data->philos[i].is_hungry;
	}
	return (ret);
}

void	print_message(t_data *data)
{
	int		i;
	char	*msg;

	i = select_earliest_msg(data->philos, data->opt.number_of_philosophers);
	if (i != EMPTY)
	{
		msg = get_msg_from_type(data->philos[i].buffer_msg->type_msg);
		printf("%llu philo %d %s\n",
			data->philos[i].buffer_msg->timestamp, i, msg);
		pthread_mutex_lock(&data->philos[i].shut_up);
		pop_msg(&data->philos[i].buffer_msg);
		pthread_mutex_unlock(&data->philos[i].shut_up);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		ret;

	ret = EXIT_SUCCESS;
	if (init_data((argc - 1), argv, &data) == EXIT_FAILURE)
		ret = EXIT_FAILURE;
	else if (init_philos(&data) == EXIT_FAILURE)
		ret = EXIT_FAILURE;
	else
	{
		pthread_mutex_unlock(&data.start);
		printf("Start\n");
		while (nobody_dead(&data) && someone_hungry(&data))
			print_message(&data);
	}
	return (ret);
}
