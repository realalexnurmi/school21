/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:46:57 by enena             #+#    #+#             */
/*   Updated: 2021/03/12 05:31:58 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	main_loop(t_game_master *gm)
{
	if (gm->keys->any_is_pressed)
		key_check(gm);
	if (gm->render->need)
	{
		render_frame(gm);
		mlx_put_image_to_window(gm->mlx, gm->win, gm->frame->img, 0, 0);
	}
	return (0);
}

void		game(t_game_master *gm)
{
	mlx_hook(gm->win, 2, 1L << 0, &key_press, gm->keys);
	mlx_hook(gm->win, 3, 1L << 1, &key_release, gm->keys);
	mlx_hook(gm->win, 17, 1L << 1, &exit_ok, gm);
	mlx_loop_hook(gm->mlx, &main_loop, gm);
	mlx_do_sync(gm->mlx);
	mlx_loop(gm->mlx);
}
