/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nofge_func_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:14:14 by enena             #+#    #+#             */
/*   Updated: 2021/02/12 05:26:37 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

t_bool	ft_n_func(void *node)
{
	t_list_prf	*lp;

	lp = (t_list_prf *)node;
	if (lp->size == none)
		**((int **)lp->p_cnt) = lp->begin + lp->ofst;
	if (lp->size == l)
		**((long int **)lp->p_cnt) = lp->begin + lp->ofst;
	if (lp->size == ll)
		**((long long int **)lp->p_cnt) = lp->begin + lp->ofst;
	if (lp->size == h)
		**((short int **)lp->p_cnt) = lp->begin + lp->ofst;
	if (lp->size == hh)
		**((t_schar **)lp->p_cnt) = lp->begin + lp->ofst;
	if (lp->size == z)
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
	if (!(print = ft_take_prec_int(lp, print, FALSE)))
		return (FALSE);
	if (!(print = ft_hash(lp, print)))
		return (FALSE);
	if (!(lp->print = ft_make_min_width(lp, print)))
		return (FALSE);
	return (TRUE);
}

t_bool	ft_f_func(void *node)
{
	t_list_prf		*lp;
	char			*print;
	t_bool			issign;
	char			sign;
	int				prec;

	lp = (t_list_prf *)node;
	prec = (lp->prec ? *lp->prec : 6) + !!(lp->flag & HASH_FLAG);
	if (!(print = ft_dtoa(*((double *)lp->p_cnt), prec)))
		return (FALSE);
	ft_isspecialfloat(print, &(lp->flag));
	if (!(print = ft_hash(lp, print)))
		return (FALSE);
	if (!(print = ft_take_space_plus(lp, print)))
		return (FALSE);
	if (!!(issign = !(ft_isdigit(*print))))
		ft_takesign(&sign, print);
	if (!(lp->print = ft_make_min_width(lp, print)))
		return (FALSE);
	if (lp->flag & UPCS_FLAG)
		ft_upper(lp->print);
	if (issign)
		ft_addsign(sign, lp->print);
	return (TRUE);
}

t_bool	ft_e_func(void *node)
{
	t_list_prf		*lp;
	char			*print;
	t_bool			issign;
	char			sign;
	int				prec;

	lp = (t_list_prf *)node;
	prec = (lp->prec ? *lp->prec : 6) + !!(lp->flag & HASH_FLAG);
	if (!(print = ft_convert_in_scientific(*((double *)lp->p_cnt),
					prec, &(lp->flag))))
		return (FALSE);
	if (!(print = ft_take_space_plus(lp, print)))
		return (FALSE);
	if (!!(issign = !(ft_isdigit(*print))))
		ft_takesign(&sign, print);
	if (!(lp->print = ft_make_min_width(lp, print)))
		return (FALSE);
	if (lp->flag & UPCS_FLAG)
		ft_upper(lp->print);
	if (issign)
		ft_addsign(sign, lp->print);
	return (TRUE);
}

t_bool	ft_g_func(void *node)
{
	t_list_prf		*lp;
	char			*print;
	t_bool			issign;
	char			sign;
	int				prec;

	lp = (t_list_prf *)node;
	prec = (lp->prec ? *lp->prec + (*lp->prec == 0) : 6);
	if (!(print = ft_convert_in_scientific(*((double *)lp->p_cnt),
					prec - 1, &(lp->flag))))
		return (FALSE);
	if (!(print = ft_g_convert(print, prec, *((double *)lp->p_cnt),
					&(lp->flag))))
		return (FALSE);
	if (!(print = ft_take_space_plus(lp, print)))
		return (FALSE);
	if (!!(issign = !(ft_isdigit(*print))))
		ft_takesign(&sign, print);
	if (!(lp->print = ft_make_min_width(lp, print)))
		return (FALSE);
	if (lp->flag & UPCS_FLAG)
		ft_upper(lp->print);
	if (issign)
		ft_addsign(sign, lp->print);
	return (TRUE);
}
