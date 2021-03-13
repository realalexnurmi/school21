/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:43:39 by enena             #+#    #+#             */
/*   Updated: 2021/03/09 07:23:36 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game_master gm;

	if (!(init_gm(&gm, argc, argv)))
		escape_deal(&gm);
	else
	{
		if (!(get_table(&gm.table)) ||
			!(render_init(&gm)))
			escape_deal(&gm);
		if (gm.save)
			do_bmp_from_frame(&gm, argv[1]);
		game(&gm);
	}
	return (0);
}
