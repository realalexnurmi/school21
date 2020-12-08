/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_printf_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:34:20 by enena             #+#    #+#             */
/*   Updated: 2020/12/08 15:28:43 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list_prf		*ft_lstprf_new(size_t begin, size_t end, t_func_do func)
{
	t_list_prf	*new;

	new = NULL;
	if (!(new = malloc(sizeof(t_list_prf))))
		return (NULL);
	new->next = NULL;
	new->ofst = 0;
	new->begin = begin;
	new->end = end;
	new->func = func;
	new->flag = NONE_FLAG;
	new->width = NULL;
	new->prec = NULL;
	new->size = NONE;
	new->p_cnt = NULL;
	new->print = NULL;
	return (new);
}

void			ft_lstprf_addback(t_list_prf **lst, t_list_prf *new)
{
	if (new)
	{
		if (*lst)
			ft_lstprf_last(*lst)->next = new;
		else
			*lst = new;
	}
}

t_list_prf		*ft_lstprf_last(t_list_prf *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

size_t			ft_lstprf_size(t_list_prf *lst)
{
	size_t	cnt;

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
