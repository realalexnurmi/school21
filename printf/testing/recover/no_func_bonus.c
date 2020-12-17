/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_func_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:48:31 by enena             #+#    #+#             */
/*   Updated: 2020/12/16 21:49:32 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_bool	ft_o_func(void *node)
{
	t_list_prf		*lp;
	char			*print;
	t_ullint	num;

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
