/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cs_prc_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:32:38 by enena             #+#    #+#             */
/*   Updated: 2020/12/21 21:46:51 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool	ft_s_func(void *node)
{
	t_list_prf	*lp;
	char		*print;

	lp = (t_list_prf *)node;
	if (!(print = ft_strdup(*((char **)lp->p_cnt))))
		return (FALSE);
	ft_take_prec_str(lp, print);
	if (!(lp->print = ft_make_min_width(lp, print)))
		return (FALSE);
	return (TRUE);
}

t_bool	ft_c_func(void *node)
{
	t_list_prf	*lp;
	char		*print;

	lp = (t_list_prf *)node;
	if (!(print = ft_calloc(2, sizeof(char))))
		return (FALSE);
	print[0] = *((char *)lp->p_cnt);
	if (!(lp->print = ft_make_min_width(lp, print)))
		return (FALSE);
	return (TRUE);
}

t_bool	ft_prc_func(void *node)
{
	t_list_prf	*lp;
	char		*print;

	lp = (t_list_prf *)node;
	if (!(print = ft_calloc(2, sizeof(char))))
		return (FALSE);
	print[0] = '%';
	if (!(lp->print = ft_make_min_width(lp, print)))
		return (FALSE);
	return (TRUE);
}
