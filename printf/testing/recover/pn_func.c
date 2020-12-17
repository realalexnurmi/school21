/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pn_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:00:01 by enena             #+#    #+#             */
/*   Updated: 2020/12/15 22:17:50 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool	ft_p_func(void *node)
{
	t_list_prf	*lp;
	char		*print;

	lp = (t_list_prf *)node;
	lp->flag |= HASH_FLAG;
	lp->size = L;
	return (ft_x_func(node));
}

t_bool	ft_n_func(void *node)
{
	t_list_prf	*lp;
	char		*print;

	lp = (t_list_prf *)node;
	if (lp->size == NONE)
		**((int **)lp->p_cnt) = lp->begin + lp->ofst;
	if (lp->size == L)
		**((long int **)lp->p_cnt) = lp->begin + lp->ofst;
	if (lp->size == LL)
		**((long long int **)lp->p_cnt) = lp->begin + lp->ofst;
	if (lp->size == H)
		**((short int **)lp->p_cnt) = lp->begin + lp->ofst;
	if (lp->size == HH)
		**((t_schar **)lp->p_cnt) = lp->begin + lp->ofst;
	if (lp->size == Z)
		**((ssize_t **)lp->p_cnt) = lp->begin + lp->ofst;
	if (!(lp->print = ft_calloc(1, sizeof(char))))
		return (FALSE);
	return (TRUE);
}
