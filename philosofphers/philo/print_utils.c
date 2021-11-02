/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 04:27:48 by enena             #+#    #+#             */
/*   Updated: 2021/11/02 07:04:28 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	select_earliest_msg(t_philo *philos, int count_philos)
{
	int	i;
	int	index_earliest;

	i = PRESTART;
	index_earliest = EMPTY;
	while (++i < count_philos)
	{
		if (philos[i].buffer_msg)
		{
			if (index_earliest == EMPTY || philos[i].buffer_msg->timestamp
				< philos[index_earliest].buffer_msg)
				index_earliest = i;
		}
	}
	return (index_earliest);
}

char	*get_msg_from_type(t_type_msg type_msg)
{
	char	*msg;

	if (type_msg == left)
		msg = " has taken a left fork.";
	if (type_msg == right)
		msg = " has taken a right fork.";
	if (type_msg == eat)
		msg = " is eating.";
	if (type_msg == sleep)
		msg = " is sleeping.";
	if (type_msg == think)
		msg = " is thinking.";
	return (msg);
}

void	push_msg(t_msg **msg_buffer, t_ms timestamp, t_type_msg type_msg)
{
	t_msg	*temp;
	t_msg	*new;

	new = malloc(sizeof(t_msg));
	new->timestamp = timestamp;
	new->type_msg = type_msg;
	new->next = NULL;
	if (!*msg_buffer)
		*msg_buffer = new;
	else
	{
		temp = *msg_buffer;
		while (temp->next)
			temp = temp->next;
		temp->next = new;	
	}
}

void	pop_msg(t_msg **msg_buffer)
{
	t_msg	*del;

	del = *msg_buffer;
	*msg_buffer = (*msg_buffer)->next;
	if (del)
	{
		free(del);
		del = NULL;
	}
}
