/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 04:28:06 by enena             #+#    #+#             */
/*   Updated: 2021/11/04 12:34:33 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(int c)
{
	int	ret;

	ret = FALSE;
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		ret = TRUE;
	return (ret);
}

static int	ft_isdigit(int c)
{
	int	ret;

	ret = FALSE;
	if ((c >= '0') && (c <= '9'))
		ret = TRUE;
	return (ret);
}

static int	ft_atoi(const char *str)
{
	long long int	ret;
	char			sign;

	ret = 0;
	while (*str && ft_isspace((int)*str))
		str++;
	sign = 1 - 2 * (*str == '-');
	str += (*str == '-' || *str == '+');
	while ((*str && ft_isdigit((int)*str)))
	{
		ret = ret * 10 + ((*str - '0') * sign);
		if (ret && (ret * sign < 0))
		{
			ret = -1 * (sign > 0);
			break ;
		}
		str++;
	}
	return ((int)ret);
}

static int	options_is_correct(int count, t_info *options)
{
	int	ret;

	ret = TRUE;
	if (options->number_of_philosophers <= 0
		|| options->time_to_die <= 0
		|| options->time_to_eat <= 0
		|| options->time_to_sleep <= 0
		|| (count == 5 && options->number_of_times_each_philo_must_eat <= 0))
		ret = FALSE;
	return (ret);
}

int	get_options(int count_options, char **value_options, t_info *info)
{
	int	ret;

	ret = EXIT_SUCCESS;
	if (count_options < 4 || count_options > 5)
		ret = EXIT_FAILURE;
	else
	{
		info->number_of_philosophers = ft_atoi(value_options[1]);
		info->time_to_die = ft_atoi(value_options[2]);
		info->time_to_eat = ft_atoi(value_options[3]);
		info->time_to_sleep = ft_atoi(value_options[4]);
		if (count_options == 5)
			info->number_of_times_each_philo_must_eat = \
			ft_atoi(value_options[5]);
		else
			info->number_of_times_each_philo_must_eat = EMPTY;
		if (options_is_correct(count_options, info) == FALSE)
			ret = EXIT_FAILURE;
	}
	return (ret);
}
