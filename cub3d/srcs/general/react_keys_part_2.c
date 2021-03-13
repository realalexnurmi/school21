/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   react_keys_part_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 03:50:42 by enena             #+#    #+#             */
/*   Updated: 2021/03/09 07:52:01 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	exit_ok(void *pgm)
{
	g_error_callback = 0;
	escape_deal(pgm);
	return (0);
}

int	rotate_counter_clock(void *pgm)
{
	t_game_master	*gm;

	gm = pgm;
	rotate(&gm->pl->dir_x, &gm->pl->dir_y, gm->table[counter_clock]);
	rotate(&gm->pl->pln_x, &gm->pl->pln_y, gm->table[counter_clock]);
	rotate(&gm->pl->strafe_l_x, &gm->pl->strafe_l_y, gm->table[counter_clock]);
	gm->render->need = true;
	return (0);
}

int	rotate_clockwise(void *pgm)
{
	t_game_master	*gm;

	gm = pgm;
	rotate(&gm->pl->dir_x, &gm->pl->dir_y, gm->table[clockwise]);
	rotate(&gm->pl->pln_x, &gm->pl->pln_y, gm->table[clockwise]);
	rotate(&gm->pl->strafe_l_x, &gm->pl->strafe_l_y, gm->table[clockwise]);
	gm->render->need = true;
	return (0);
}
