/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_things_part_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 23:51:22 by enena             #+#    #+#             */
/*   Updated: 2021/03/14 00:19:44 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruments.h"

/*
** Puting clr to [x,y] image data
*/

void	put_pxl_to_img(t_image *data, int x, int y, t_uint clr)
{
	char	*dst;
	int		offset;

	offset = y * data->len_line + x * data->bytepp;
	dst = data->addr + offset;
	*(t_uint*)dst = clr;
}

t_uint	get_color_from_img(t_image *data, int x, int y)
{
	char	*dst;
	int		offset;

	offset = y * data->len_line + x * data->bytepp;
	dst = data->addr + offset;
	return (*(t_uint *)dst);
}

void	calculate_edge(int *begin, int *end, int max, int value)
{
	int	half_max;
	int	half_value;

	half_max = max / 2;
	half_value = value / 2;
	*begin = half_max - half_value;
	if (*begin < 0)
		*begin = 0;
	*end = half_max + half_value;
	if (*end > max)
		*end = max;
}
