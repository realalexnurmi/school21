/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:04:27 by enena             #+#    #+#             */
/*   Updated: 2021/03/09 21:40:34 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"
#include "bmp_utils.h"
#include "naming_utils.h"

void	do_bmp_from_frame(t_game_master *gm, const char *map_name)
{
	const int	width = ((t_resolution *)gm->sl->link[resolution].get)->width;
	const int	height = ((t_resolution *)gm->sl->link[resolution].get)->height;
	char		*filename;

	if ((width > BMP_MAX_DIMENSION) || (height > BMP_MAX_DIMENSION))
	{
		error_handler(err_too_big_save_bmp);
		escape_deal(gm);
	}
	render_frame(gm);
	if (!(put_name_screenshot(&filename, map_name, gm->frame)) ||
		!(save_image_as_bmp(gm->frame, filename)))
		escape_deal(gm);
	exit_ok(gm);
}
