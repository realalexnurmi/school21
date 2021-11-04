/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 04:27:48 by enena             #+#    #+#             */
/*   Updated: 2021/11/04 18:14:24 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*get_msg_from_type(t_status type_msg)
{
	char	*msg;

	if (type_msg == take_left_fork)
		msg = "has taken a left fork.";
	if (type_msg == take_right_fork)
		msg = "has taken a right fork.";
	if (type_msg == eating)
		msg = "is eating.";
	if (type_msg == sleeping)
		msg = "is sleeping.";
	if (type_msg == thinking)
		msg = "is thinking.";
	return (msg);
}
