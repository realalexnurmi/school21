/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:51:01 by enena             #+#    #+#             */
/*   Updated: 2021/03/09 06:08:17 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

static void	init_key(t_key *key, int keycode, t_key_react react)
{
	key->status = released;
	key->code = keycode;
	key->react = react;
}

t_bool		keys_init(t_keys **keys)
{
	t_keys		*tmp;

	tmp = *keys;
	if (!(tmp = malloc(sizeof(t_keys))))
		return (error_handler(err_alloc_fail));
	tmp->any_is_pressed = false;
	tmp->key = NULL;
	if (!(tmp->key = malloc((CNT_KEY_REACT) * sizeof(t_key))))
		return (error_handler(err_alloc_fail));
	init_keys_group_1(tmp->key);
	*keys = tmp;
	return (true);
}

void		init_keys_group_1(t_key *keys)
{
	init_key(&keys[w], 13, &move_forward);
	init_key(&keys[a], 0, &strafe_left);
	init_key(&keys[s], 1, &move_backward);
	init_key(&keys[d], 2, &strafe_right);
	init_key(&keys[left], 123, &rotate_counter_clock);
	init_key(&keys[right], 124, &rotate_clockwise);
	init_key(&keys[esc], 53, &exit_ok);
}
