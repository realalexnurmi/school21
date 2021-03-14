/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 06:09:48 by enena             #+#    #+#             */
/*   Updated: 2021/03/14 06:17:04 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruments.h"

void		draw_ceil(t_ray *ray, t_uint *color, t_image *frame)
{
	ssize_t	y;
	t_uint	ceil;

	y = -1;
	ceil = *color;
	while (++y < ray->wall_top)
		put_pxl_to_img(frame, ray->ind, y, ceil);
}

void		draw_floor(t_ray *ray, t_uint *color, t_image *frame)
{
	ssize_t	y;
	t_uint	floor;

	y = ray->wall_bot - 1;
	floor = *color;
	while (++y < frame->height)
		put_pxl_to_img(frame, ray->ind, y, floor);
}

void		draw_wall(t_ray *ray, t_wall *wall, t_image *frame)
{
	ssize_t	y;
	t_uint	color;

	y = ray->wall_top - 1;
	while (++y < ray->wall_bot)
	{
		wall->texture_y = (int)wall->y;
		wall->y += wall->step_y;
		color = 0x00FFFFFF &
		get_color_from_img(wall->texture, wall->texture_x, wall->texture_y);
		put_pxl_to_img(frame, ray->ind, y, color);
	}
}

void		draw_sprite(t_sprite *sprite, t_ray *rays, t_image *texture,
															t_image *frame)
{
	ssize_t	yx[2];
	int		tex_yx[2];
	int		d;
	t_uint	color;

	yx[1] = sprite->x_draw_begin - 1;
	while (++yx[1] < sprite->x_draw_end)
	{
		tex_yx[1] = (int)(yx[1] - (sprite->cntr - sprite->width / 2)) *
			texture->width / sprite->width;
		if (sprite->perp_dist > 0.1 &&
			sprite->perp_dist < rays[yx[1]].perp_dist)
		{
			yx[0] = sprite->y_draw_begin - 1;
			while (++yx[0] < sprite->y_draw_end)
			{
				d = 2 * yx[0] - frame->height + sprite->height;
				tex_yx[0] = ((d * texture->height) / sprite->height) / 2;
				color = get_color_from_img(texture, tex_yx[1], tex_yx[0]);
				if ((color & 0xFF000000) == 0)
					put_pxl_to_img(frame, yx[1], yx[0], color);
			}
		}
	}
}
