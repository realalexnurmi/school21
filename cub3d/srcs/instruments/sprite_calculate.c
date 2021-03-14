/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_calculate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:15:16 by enena             #+#    #+#             */
/*   Updated: 2021/03/14 05:57:52 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruments.h"

static void	calc_sprite(t_sprite *sp, t_player *pl, t_image *frame)
{
	float	sprite_x;
	float	sprite_y;
	float	inv_det;
	float	x_offset;

	sprite_x = sp->x - pl->x;
	sprite_y = sp->y - pl->y;
	inv_det = 1.0 / (pl->pln_x * pl->dir_y - pl->dir_x * pl->pln_y);
	x_offset = inv_det * (pl->dir_y * sprite_x - pl->dir_x * sprite_y) *
				2.0 / FOV;
	sp->perp_dist = inv_det * (-pl->pln_y * sprite_x + pl->pln_x * sprite_y);
	sp->cntr = (int)((frame->width / 2) * (1 + x_offset / sp->perp_dist));
	sp->height = (int)(fabs(frame->width / FOV / sp->perp_dist));
	calculate_edge(&(sp->y_draw_begin), &(sp->y_draw_end),
						frame->height, sp->height);
	sp->width = (int)(fabs(frame->width / FOV / sp->perp_dist));
	sp->x_draw_begin = sp->cntr - sp->width / 2;
	if (sp->x_draw_begin < 0)
		sp->x_draw_begin = 0;
	sp->x_draw_end = sp->cntr + sp->width / 2;
	if (sp->x_draw_end >= frame->width)
		sp->x_draw_end = frame->width;
}

void		calculate_sprites(t_sprite ***arr, t_player *pl,
											ssize_t count_s, t_image *frame)
{
	ssize_t			i;
	static float	sort_prev_x = -1.0;
	static float	sort_prev_y = -1.0;

	if (fabs(sort_prev_x - pl->x) >= 0.5 || fabs(sort_prev_y - pl->y) >= 0.5)
	{
		i = -1;
		while (++i < count_s)
			(*arr)[i]->dist_pow2 = pow((pl->x - (*arr)[i]->x), 2) +
								pow((pl->y - (*arr)[i]->y), 2);
		improve_quick_sort(arr, 0, count_s - 1);
		sort_prev_x = pl->x;
		sort_prev_y = pl->y;
	}
	i = -1;
	while (++i < count_s)
		calc_sprite((*arr)[i], pl, frame);
}
