/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:11:55 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:33:20 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function returns the number of nodes [cnt] in the SLL list [lst] (aka size)
*/

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	cnt = 0;
	if (lst)
	{
		cnt++;
		while (lst->next)
		{
			lst = lst->next;
			cnt++;
		}
	}
	return (cnt);
}
