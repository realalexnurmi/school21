/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruments.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:50:09 by enena             #+#    #+#             */
/*   Updated: 2021/02/28 11:06:16 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUMENTS_H
# define INSTRUMENTS_H
# include "libft.h"
# include "defines.h"
# include "structs.h"
# include "error_handling.h"

/*
** common_things_part_1
*/

void	put_pxl_to_img(t_image *data, int x, int y, t_uint clr);

#endif
