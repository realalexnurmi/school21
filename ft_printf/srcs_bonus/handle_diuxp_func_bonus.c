/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_diuxp_func_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 00:03:27 by enena             #+#    #+#             */
/*   Updated: 2020/12/23 00:28:58 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool	ft_di_func(void *node)
{
	t_list_prf		*lp;
	char			*print;
	long long int	num;
	t_bool			issign;
	char			sign;

	lp = (t_list_prf *)node;
	num = ft_take_signed(lp);
	if (!(print = ft_lltoa_base(num, 10)))
		return (FALSE);
	if (!(print = ft_take_space_plus(lp, print)))
		return (FALSE);
	issign = !(ft_isdigit(*print));
	if (issign)
		ft_takesign(&sign, print);
	if (!(print = ft_take_prec_int(lp, print, issign)))
		return (FALSE);
	if (!(lp->print = ft_make_min_width(lp, print)))
		return (FALSE);
	if (issign)
		ft_addsign(sign, lp->print);
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
	if (!(print = ft_take_prec_int(lp, print, FALSE)))
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
	if (!(print = ft_take_prec_int(lp, print, FALSE)))
		return (FALSE);
	if (num != 0 || lp->func == ft_p_func)
		if (!(print = ft_hash(lp, print, TRUE)))
			return (FALSE);
	if (!(lp->print = ft_make_min_width(lp, print)))
		return (FALSE);	
	if (num != 0 && lp->flag & HASH_FLAG)
		ft_checkXhash(lp->print);
	if (lp->flag & UPCS_FLAG)
		ft_upper(lp->print);
	return (TRUE);
}

t_bool	ft_p_func(void *node)
{
	t_list_prf	*lp;

	lp = (t_list_prf *)node;
	lp->flag |= HASH_FLAG;
	lp->size = L;
	return (ft_x_func(node));
}
