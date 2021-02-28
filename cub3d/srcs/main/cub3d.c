/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:43:39 by enena             #+#    #+#             */
/*   Updated: 2021/02/28 18:07:30 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game_master gm;

	if (!(init_gm(&gm, argc, argv)))
		printf("sorry\n");//escape_deal(&gm);
	else
	{
		mlx_put_image_to_window(gm.mlx, gm.win, ((t_image *)gm.sl->link[no_texture].get)->img, 0, 0);
		mlx_loop(gm.mlx);
	}
	return (0);
}
