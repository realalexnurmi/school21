/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 05:13:40 by enena             #+#    #+#             */
/*   Updated: 2021/03/09 07:52:47 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H
# include "libft.h"
# include "defines.h"
# include "structs.h"
# include "error_handling.h"
# include "instruments.h"

void	do_bmp_from_frame(t_game_master *gm, const char *map_name);

int		key_press(int keycode, t_keys *keys);
int		key_release(int keycode, t_keys *keys);
int		key_check(t_game_master *gm);

int		exit_ok(void *pgm);
int		move_forward(void *pgm);
int		move_backward(void *pgm);
int		strafe_right(void *pgm);
int		strafe_left(void *pgm);

int		rotate_counter_clock(void *pgm);
int		rotate_clockwise(void *pgm);

void	game(t_game_master *gm);

void	render_frame(t_game_master *gm);
#endif
