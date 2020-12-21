/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprf_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:50:11 by enena             #+#    #+#             */
/*   Updated: 2020/12/21 21:46:26 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list_prf	*ft_lstprf_new(size_t begin, size_t end, t_func_do func)
{
	t_list_prf	*new;

	new = NULL;
	if (!(new = malloc(sizeof(t_list_prf))))
		return (NULL);
	new->next = NULL;
	new->begin = begin;
	new->end = end;
	new->func = func;
	new->flag = NONE_FLAG;
	new->width = NULL;
	new->prec = NULL;
	new->p_cnt = NULL;
	new->print = NULL;
	return (new);
}
