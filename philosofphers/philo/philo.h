/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 04:27:30 by enena             #+#    #+#             */
/*   Updated: 2021/11/02 07:25:52 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0
# define EMPTY -1
# define PRESTART -1

typedef struct s_options
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philo_must_eat;
}	t_options;

typedef unsigned long long int	t_ms;

typedef enum e_type_msg
{
	left,
	right,
	eat,
	sleep,
	think
}	t_type_msg;

typedef struct s_msg
{
	t_ms		timestamp;
	t_type_msg	type_msg;
	t_msg		*next;
}	t_msg;


typedef struct s_philo
{
	int				index;
	int				is_alive;
	int				is_hungry;
	int				left_to_eat;
	pthread_t		thread;
	t_ms			start_time;
	t_msg			*buffer_msg;
	pthread_mutex_t	*shut_up;
	pthread_mutex_t *start;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_data
{
	t_options		opt;
	pthread_mutex_t	start;
	t_philo			*philos;
}	t_data;

int		get_options(int count_options, char **value_options, t_data *data);
int		init_data(int count_options, char **value_options, t_data *data);
int		init_philos(t_data *data);
t_ms	get_current_ms(void);
void	*philo_life(t_philo *philo);
int		select_earliest_msg(t_philo *philos, int count_philos);

#endif