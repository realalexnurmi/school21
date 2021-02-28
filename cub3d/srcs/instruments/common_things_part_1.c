/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_things_part_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 23:51:22 by enena             #+#    #+#             */
/*   Updated: 2021/02/28 11:09:37 by enena            ###   ########.fr       */
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

	offset = pxl->y * data->len_line + pxl->x * data->bytepp;
	dst = data->addr + offset;
	*(t_uint*)dst = pxl->clr;
}
