/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_part_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 02:41:49 by enena             #+#    #+#             */
/*   Updated: 2021/01/27 02:41:51 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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