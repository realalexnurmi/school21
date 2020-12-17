/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nofge_func_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:14:14 by enena             #+#    #+#             */
/*   Updated: 2020/12/17 23:24:00 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

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

t_bool	ft_o_func(void *node)
{
	t_list_prf		*lp;
	char			*print;
	t_ullint		num;

	lp = (t_list_prf *)node;
	num = ft_take_unsigned(lp);
	if (!(print = ft_ulltoa_base(num, 8)))
		return (FALSE);
	if (!(print = ft_take_prec_dioux(lp, print)))
		return (FALSE);
	if (!(print = ft_hash(lp, print, FALSE)))
		return (FALSE);
	if (!(lp->print = ft_make_min_width(lp, print)))
		return (FALSE);
	return (TRUE);
}

t_bool	ft_f_func(void *node)
{
	return (TRUE);
}

t_bool	ft_g_func(void *node)
{
	return (TRUE);
}

t_bool	ft_e_func(void *node)
{
	return (TRUE);
}
