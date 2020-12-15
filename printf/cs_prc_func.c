/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_prc_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:45:09 by enena             #+#    #+#             */
/*   Updated: 2020/12/15 01:31:50 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool	ft_s_func(void *node)
{
	t_list_prf	*lp;
	char		*print;

	lp = (t_list_prf *)node;
	if (lp->size == L)
	{
		if (!(print = ft_wcstombs(*((wchar_t **)lp->p_cnt))))
			return (FALSE);
	}
	else if (!(print = ft_strdup(*((char **)lp->p_cnt))))
		return (FALSE);
	ft_take_prec(lp, print);
	if(!(lp->print = ft_make_min_width(lp, print)))
		return (FALSE);
	return (TRUE);
}

t_bool	ft_c_func(void *node)
{
	t_list_prf	*lp;
	char		*print;

	lp = (t_list_prf *)node;
	if (lp->size == L)
	{
		if (!(print = ft_calloc(ft_wclen(*((wchar_t *)lp->p_cnt)) + 1,
						sizeof(char))))
			return (FALSE);
		if (!(print = ft_wctomb(*((wchar_t *)lp->p_cnt), print)))
			return (FALSE);
	}
	else
	{
		if (!(print = ft_calloc(2, sizeof(char))))
			return (FALSE);
		print[0] = *((char *)lp->p_cnt);
	}
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
