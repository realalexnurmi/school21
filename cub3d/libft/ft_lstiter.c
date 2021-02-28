/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:09:58 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:32:57 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applying function [f] for every node of SLL list [lst]
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f)
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
}
