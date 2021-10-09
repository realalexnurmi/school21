/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:21:27 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:21:28 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Function adding a new node [new] to the begin of the SLL list [lst]
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}
