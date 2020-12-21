/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:53:49 by enena             #+#    #+#             */
/*   Updated: 2020/12/22 01:35:43 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_lstprf_del(t_list_prf *curr_del)
{
	if (curr_del)
	{
		if (curr_del->width)
			free(curr_del->width);
		if (curr_del->prec)
			free(curr_del->prec);
		if (curr_del->p_cnt)
			free(curr_del->p_cnt);
		if (curr_del->print)
			free(curr_del->print);
		free(curr_del);
	}
}

void	ft_lstprf_del_first(t_list_prf **head_list)
{
	t_list_prf	*next;

	if (*head_list)
	{
		next = (*head_list)->next;
		ft_lstprf_del(*head_list);
		*head_list = next;
	}
}

void	ft_lstprf_clear(t_list_prf **head_list)
{
	while (*head_list)
		ft_lstprf_del_first(head_list);
}
