/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   react_keys_part_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 03:45:47 by enena             #+#    #+#             */
/*   Updated: 2021/03/09 07:51:56 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static float	warp(float coord)
{
	int	warp;

	warp = coord / MAX_RENDER_DISTANCE;
	coord += warp * -2 * MAX_RENDER_DISTANCE + warp;
	return (coord);
}

int				move_forward(void *pgm)
{
	t_game_master	*gm;

	gm = pgm;
	gm->pl->x += gm->pl->dir_x * (MOVE_SPEED);
	gm->pl->y += gm->pl->dir_y * (MOVE_SPEED);
	gm->pl->x = warp(gm->pl->x);
	gm->pl->y = warp(gm->pl->y);
	gm->render->need = true;
	return (0);
}

int				move_backward(void *pgm)
{
	t_game_master	*gm;

	gm = pgm;
	gm->pl->x -= gm->pl->dir_x * (MOVE_SPEED);
	gm->pl->y -= gm->pl->dir_y * (MOVE_SPEED);
	gm->pl->x = warp(gm->pl->x);
	gm->pl->y = warp(gm->pl->y);
	gm->render->need = true;
	return (0);
}

int				strafe_right(void *pgm)
{
	t_game_master	*gm;

	gm = pgm;
	gm->pl->x += gm->pl->strafe_l_x * (MOVE_SPEED);
	gm->pl->y += gm->pl->strafe_l_y * (MOVE_SPEED);
	gm->pl->x = warp(gm->pl->x);
	gm->pl->y = warp(gm->pl->y);
	gm->render->need = true;
	return (0);
}

int				strafe_left(void *pgm)
{
	t_game_master	*gm;

	gm = pgm;
	gm->pl->x -= gm->pl->strafe_l_x * (MOVE_SPEED);
	gm->pl->y -= gm->pl->strafe_l_y * (MOVE_SPEED);
	gm->pl->x = warp(gm->pl->x);
	gm->pl->y = warp(gm->pl->y);
	gm->render->need = true;
	return (0);
}
