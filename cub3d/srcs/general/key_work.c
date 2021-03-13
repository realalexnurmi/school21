/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 03:21:47 by enena             #+#    #+#             */
/*   Updated: 2021/03/07 07:46:56 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	key_press(int keycode, t_keys *keys)
{
	t_key	*key;
	ssize_t	i;

	key = keys->key;
	i = -1;
	while (++i < CNT_KEY_REACT)
	{
		if (key[i].code == keycode)
		{
			key[i].status = pressed;
			keys->any_is_pressed = true;
		}
	}
	return (0);
}

int	key_release(int keycode, t_keys *keys)
{
	t_key	*key;
	t_bool	all_released;
	ssize_t	i;

	key = keys->key;
	all_released = true;
	i = -1;
	while (++i < CNT_KEY_REACT)
	{
		if (key[i].code == keycode)
			key[i].status = released;
		all_released = all_released && (key[i].status == released);
	}
	keys->any_is_pressed = !(all_released);
	return (0);
}

int	key_check(t_game_master *gm)
{
	t_key	*key;
	ssize_t	i;

	key = gm->keys->key;
	i = -1;
	while (++i < CNT_KEY_REACT)
		if (key[i].status == pressed)
			key[i].react(gm);
	return (0);
}
