/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_things_part_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 23:51:22 by enena             #+#    #+#             */
/*   Updated: 2021/01/26 23:54:15 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Convert coordinate into point
*/
t_point	get_point(float x, float y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

/*
** Convert point into pixel
*/
t_pxl	get_pxl(t_point crd)//, t_rule rule)
{
	t_pxl	pxl;

	pxl.x = trunc(crd.x);
	pxl.y = trunc(crd.y);
	//pxl.rule = rule;
	return (pxl);
}

/*
** Puting pixel to image
*/
void	put_pxl_to_img(t_image *data, t_pxl pxl)
{
	char	*dst;
	int		offset;

	offset = (pxl.y * data->len_line + pxl.x * (data->bpp / 8));
	dst = data->addr + offset;
	*(t_uint*)dst = 0x00EF4135;//get_color_data(get_clr(0x00FFFFFF));//(took_clr(pxl.rule));
}

/*
** Adding data color into pxl image color with intensity {0.0 ~ < 1.0}
*/
// void	add_pxl_to_img(t_image *data, t_pxl pxl, float intensity)
// {
// 	char	*dst;
// 	int		offset;
// 	t_clr	base;
// 	t_clr	add;

// 	if (intensity >= 1.0)
// 		put_pxl_to_img(data, pxl);
// 	else
// 	{
// 		if (intensity < 0.1875)
// 			intensity = 0.1875;
// 		offset = (pxl.y * data->len_line + pxl.x * (data->bpp / 8));
// 		dst = data->addr + offset;
// 		base = get_clr(*(t_uint*)dst);
// 		set_clr_br(&base, 1.0 - intensity);
// 		add = took_clr(pxl.rule);
// 		set_clr_br(&add, intensity);
// 		*(t_uint*)dst = get_color_data(get_merge_clr(base, add));
// 	}
// }