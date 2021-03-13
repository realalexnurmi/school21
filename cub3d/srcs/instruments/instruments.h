/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruments.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:50:09 by enena             #+#    #+#             */
/*   Updated: 2021/03/13 23:57:07 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUMENTS_H
# define INSTRUMENTS_H
# include "libft.h"
# include "defines.h"
# include "structs.h"
# include "error_handling.h"
# include <math.h>

/*
** common_things_part_1
*/

void	put_pxl_to_img(t_image *data, int x, int y, t_uint clr);
t_uint	get_color_from_img(t_image *data, int x, int y);
void	calculate_edge(int *begin, int *end, int max, int value);

t_bool	get_table(float ***table);
void	rotate(float *x, float *y, float *table);
void	rotate_ninety(float *x, float *y, t_dir_rotate dir);
void	find_cross(float *cross_x, float *cross_y, t_ray *ray,
										t_player *pl, t_sprite *sp);

void	draw_ceil(t_ray *ray, t_uint *color, t_image *frame);
void	draw_floor(t_ray *ray, t_uint *color, t_image *frame);
void	draw_wall(t_ray *ray, t_wall *wall, t_image *frame);
void	draw_sprite(t_sprite *sprite, t_ray *rays, t_image *texture,
										t_image *frame);

void	calculate_sprites(t_sprite ***sprites, t_player *pl,
										ssize_t count_s, t_image *frame);
void	calculate_wall(t_ray *ray, t_game_master *gm);

void	improve_quick_sort(t_sprite ***arr, size_t low, size_t high);

#endif
