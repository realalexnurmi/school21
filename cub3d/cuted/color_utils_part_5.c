/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_part_5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 04:45:35 by enena             #+#    #+#             */
/*   Updated: 2021/02/26 11:38:48 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_utils.h"


t_clr	base_clr(void *info, void *data)
{
	return (get_clr(0x00FF0000));
}

t_clr	setted_clr(void *info, void *data)
{
	return (base_clr(info, data));
}

t_clr	texture_clr(void *info, void *data)
{
	return (base_clr(info, data));
}
