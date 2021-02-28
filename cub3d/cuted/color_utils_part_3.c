/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_part_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 04:45:35 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 12:52:02 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_utils.h"

/*
** Getting Alpha component ARGB from raw color data {clr_data}
*/
t_uchar	get_a(t_uint clr_data)
{
	return ((clr_data >> 24) & 0x000000FF);
}

/*
** Getting Red component ARGB from raw color data {clr_data}
*/
t_uchar	get_r(t_uint clr_data)
{
	return ((clr_data >> 16) & 0x000000FF);
}

/*
** Getting Green component ARGB from raw color data {clr_data}
*/
t_uchar	get_g(t_uint clr_data)
{
	return ((clr_data >> 8) & 0x000000FF);
}

/*
** Getting Blue component ARGB from raw color data {clr_data}
*/
t_uchar	get_b(t_uint clr_data)
{
	return (clr_data & 0x000000FF);
}

/*
** Setting storage color struct [t_clr] 
** from ARGB component {red, green, blue}
** [t_clr.a]lpha, [t_clr.br]igthness, [t_clr.tr]ansparancy set as default
** (.a = 0; .br = 1.0; .tr = 0.0)
*/
void	set_clr(t_clr *clr, t_uchar red, t_uchar green, t_uchar blue)
{
	clr->a = 0;
	clr->r = red;
	clr->g = green;
	clr->b = blue;
	clr->br = 1.0;
	clr->tr	= 0.0;
}

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