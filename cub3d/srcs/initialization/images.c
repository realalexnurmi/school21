/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:34:58 by enena             #+#    #+#             */
/*   Updated: 2021/03/09 07:27:13 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

t_image		*get_image(void *img, int width, int height)
{
	t_image	*rt;

	if (!(rt = malloc(sizeof(t_image))))
		return (NULL);
	rt->width = width;
	rt->height = height;
	rt->img = img;
	rt->addr = mlx_get_data_addr(img, &rt->bpp, &rt->len_line, &rt->endian);
	rt->bytepp = rt->bpp / 8;
	return (rt);
}

static void	check_resolution(t_game_master *gm)
{
	int		w;
	int		h;

	mlx_get_screen_size(&w, &h);
	if (MIN_WIDTH > ((t_resolution *)gm->sl->link[resolution].get)->width)
	{
		((t_resolution *)gm->sl->link[resolution].get)->width = MIN_WIDTH;
		error_handler(wrn_resolution_width_increased);
	}
	if (MIN_HEIGHT > ((t_resolution *)gm->sl->link[resolution].get)->height)
	{
		((t_resolution *)gm->sl->link[resolution].get)->height = MIN_HEIGHT;
		error_handler(wrn_resolution_height_increased);
	}
	if (w < ((t_resolution *)gm->sl->link[resolution].get)->width)
	{
		((t_resolution *)gm->sl->link[resolution].get)->width = w;
		error_handler(wrn_resolution_width_reduced);
	}
	if (h < ((t_resolution *)gm->sl->link[resolution].get)->height)
	{
		((t_resolution *)gm->sl->link[resolution].get)->height = h;
		error_handler(wrn_resolution_height_reduced);
	}
}

t_bool		make_frame(t_game_master *gm)
{
	void *img_ptr;

	if (!(gm->save))
		check_resolution(gm);
	if (!(img_ptr = mlx_new_image(gm->mlx,
					((t_resolution *)gm->sl->link[resolution].get)->width,
					((t_resolution *)gm->sl->link[resolution].get)->height,
					0x00000000)))
		return (error_handler(err_new_image_fail));
	if (!(gm->frame = get_image(img_ptr,
					((t_resolution *)gm->sl->link[resolution].get)->width,
					((t_resolution *)gm->sl->link[resolution].get)->height)))
		return (error_handler(err_alloc_fail));
	return (true);
}

t_bool		open_window(t_game_master *gm)
{
	const t_resolution *res = gm->sl->link[resolution].get;

	if (!(gm->save))
	{
		if (!(gm->win = mlx_new_window(gm->mlx,
					res->width, res->height, BASENAME)))
			return (error_handler(err_window_not_open));
	}
	return (true);
}
