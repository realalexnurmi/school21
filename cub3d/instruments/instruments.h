/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruments.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:50:09 by enena             #+#    #+#             */
/*   Updated: 2021/01/26 21:50:11 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUMENTS_H
# define INSTRUMENTS_H
/*
** common_things_part_1
*/

t_point	get_point(float x, float y);
t_pxl	get_pxl(t_point crd, t_rule rule);
void	put_pxl_to_img(t_image *data, t_pxl pxl);
void	add_pxl_to_img(t_image *data, t_pxl pxl, float intensity);

/*
** draw_line
*/
t_bool	draw_line(t_image *data, t_line line);

#endif
