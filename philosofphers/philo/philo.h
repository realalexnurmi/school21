/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 04:27:30 by enena             #+#    #+#             */
/*   Updated: 2021/11/04 18:48:06 by enena            ###   ########.fr       */
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
# define START_MS 0
# define EMPTY -1
# define PRESTART -1
# define LAST_CHANCE 10

typedef unsigned long long int	t_ms;

typedef struct s_info
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philo_must_eat;
	pthread_mutex_t	*print;
	pthread_mutex_t	*even;
	pthread_mutex_t	*odd;
	pthread_mutex_t	*last_odd;
	t_ms			start_time;
}	t_info;

typedef enum e_status
{
	take_left_fork,
	take_right_fork,
	eating,
	sleeping,
	thinking
}	t_status;

typedef struct s_philo
{
	t_info			*info;
	int				index;
	int				is_hungry;
	int				eat_times;
	t_ms			time_last_meal;
	t_status		status;
	pthread_t		thread;
	pthread_mutex_t	*start;
	pthread_mutex_t	*dead;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_data
{
	t_info			*info;
	t_philo			*philos;
}	t_data;

int		get_options(int count_options, char **value_options, t_info *info);
int		init_info(int count_options, char **value_options, t_data *data);
int		init_philos(t_data *data);
t_ms	get_current_ms(void);
void	*philo_life(t_philo *philo);
int		select_earliest_msg(t_philo *philos, int count_philos);
char	*get_msg_from_type(t_status type_msg);
int		init_mutex(pthread_mutex_t	**mutex);
void	print_message(t_data *data);
void	sleep_carefully(t_ms time_to_sleep, t_ms part_sleep);
t_ms	timestamp(t_ms start);

#endif