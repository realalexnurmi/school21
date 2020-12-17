/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_diuxp_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:00:54 by enena             #+#    #+#             */
/*   Updated: 2020/12/17 23:56:06 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool	ft_di_func(void *node)
{
	t_list_prf		*lp;
	char			*print;
	long long int	num;

	lp = (t_list_prf *)node;
	num = ft_take_signed(lp);
	if (!(print = ft_lltoa_base(num, 10)))
		return (FALSE);
	if (!(print = ft_take_prec_int(lp, print)))
		return (FALSE);
	if (!(lp->print = ft_make_min_width(lp, print)))
		return (FALSE);
	return (TRUE);
}

t_bool	ft_u_func(void *node)
{
	t_list_prf		*lp;
	char			*print;
	t_ullint		num;

	lp = (t_list_prf *)node;
	num = ft_take_unsigned(lp);
	if (!(print = ft_ulltoa_base(num, 10)))
		return (FALSE);
	if (!(print = ft_take_prec_int(lp, print)))
		return (FALSE);
	if (!(lp->print = ft_make_min_width(lp, print)))
		return (FALSE);
	return (TRUE);
}

t_bool	ft_x_func(void *node)
{
	t_list_prf		*lp;
	char			*print;
	t_ullint		num;

	lp = (t_list_prf *)node;
	num = ft_take_unsigned(lp);
	if (!(print = ft_ulltoa_base(num, 16)))
		return (FALSE);
	if (!(print = ft_take_prec_int(lp, print)))
		return (FALSE);
	if (lp->flag & UPCS_FLAG)
		ft_upper(print);
	if (!(lp->print = ft_make_min_width(lp, print)))
		return (FALSE);
	return (TRUE);
}

t_bool	ft_p_func(void *node)
{
	t_list_prf	*lp;
	char		*print;
	char		*pr;
	t_ullint	num;

	lp = (t_list_prf *)node;
	num = *((t_ulint*)lp->p_cnt);
	if (!(pr = ft_ulltoa_base(num, 16)))
		return (FALSE);
	if (!(pr = ft_take_prec_int(lp, pr)))
		return (FALSE);
	if (!(print = ft_strjoin("0x", pr)))
		return (FALSE);
	free(pr);
	if (lp->flag & UPCS_FLAG)
		ft_upper(print);
	if (!(lp->print = ft_make_min_width(lp, print)))
		return (FALSE);
	return (TRUE);
}
