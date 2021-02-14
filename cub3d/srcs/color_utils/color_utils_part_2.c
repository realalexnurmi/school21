/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_part_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 05:06:59 by enena             #+#    #+#             */
/*   Updated: 2021/01/29 05:07:04 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_utils.h"

/*
** Set {br}igthness (br < 0.0 = 0.0) in storage color struct [t_clr] {clr}
*/
void	set_clr_br(t_clr *clr, float br)
{
	br = (br < 0.0) ? 0.0 : br;
	clr->br = br;
}

/*
** Set {tr}ansparancy (0.0 <= tr <= 1.0) in storage color struct [t_clr] {clr}
*/
void	set_clr_tr(t_clr *clr, float tr)
{
	tr = (tr < 0.0) ? 0.0 : tr;
	tr = (tr > 1.0) ? 1.0 : tr;
	clr->tr = tr;
}

/*
** Getting storage color struct [t_clr] from raw data color {clr_data}
*/
t_clr	get_clr(t_uint clr_data)
{
	t_clr	ret;

	set_clr(&ret, get_r(clr_data), get_g(clr_data), get_b(clr_data));
	set_clr_tr(&ret, get_a(clr_data) / 255);
	return (ret);
}

/*
** Combining two colors from storage color struct [t_clr] in one -> return
*/
t_clr	get_merge_clr(t_clr clr1, t_clr clr2)
{
	t_clr	ret;
	float	avg_br;
	t_uint	tmp;

	ret.tr = 1 - (1 - clr1.tr) * (1 - clr2.tr);
	ret.br = 1.0;
	avg_br = (clr1.br + clr2.br) / 2;
	clr1.br /= 2;
	clr2.br /= 2;
	tmp = clr1.r * (clr1.br/ avg_br) + clr2.r * (clr2.br/ avg_br);
	ret.r = tmp > 255 ? 255 : tmp;
	tmp = clr1.g * (clr1.br/ avg_br) + clr2.g * (clr2.br/ avg_br);
	ret.g = tmp > 255 ? 255 : tmp;
	tmp = clr1.b * (clr1.br/ avg_br) + clr2.b * (clr2.br/ avg_br);
	ret.b = tmp > 255 ? 255 : tmp;
	return (ret);
}

/*
** Getting raw color data from storage color struct [t_clr] {clr}
*/
t_uint	get_color_data(t_clr clr)
{
	t_uint	ret;
	t_uint	tmp;

	if (clr.br != 1.0)
	{
		tmp = clr.br * clr.r;
		clr.r = tmp > 255 ? 255 : tmp;
		tmp = clr.br * clr.g;
		clr.g = tmp > 255 ? 255 : tmp;
		tmp = clr.br * clr.b;
		clr.b = tmp > 255 ? 255 : tmp;
	}
	clr.a = 255 * clr.tr;
	ret = clr.a;
	ret <<= 8;
	ret |= clr.r;
	ret <<= 8;
	ret |= clr.g;
	ret <<= 8;
	ret |= clr.b;
	return (ret);
}
