/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 04:27:30 by enena             #+#    #+#             */
/*   Updated: 2021/10/31 04:27:39 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

typedef struct s_options
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philo_must_eat;
}	t_options;

typedef unsigned long long int	t_ms;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				left_to_eat;
}	t_philo;

typedef struct s_data
{
	t_options		options;
	pthread_mutex_t	start;
	pthread_mutex_t	stop;
	t_philo			*philos;
	t_ms			start_time;
}	t_data;

int		get_options(int count_options, char **value_options, t_data *data);
t_ms	get_current_ms(void);

#endif