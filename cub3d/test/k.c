/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:27:55 by enena             #+#    #+#             */
/*   Updated: 2021/02/22 21:27:59 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

t_bool	error_handler(t_error err)
{
	printf("Error\nThis error: %d\n", err);
	return (false);
}

t_bool	check_junk(const char *line, const t_error what_is_err,
	t_bool *set_pl, t_bool *only_fill)
{
	ssize_t			i;
	t_bool			find_pl;
	t_bool			is_top_or_bottom;

	is_top_or_bottom = (what_is_err == err_first_line_map ||
	what_is_err == err_last_line_map) ? true : false;
	i = -1;
	find_pl = false;
	while (line[++i])
	{
		if (!(ft_strchr(VALID_FILL_MAP_CHAR, line[i])) &&
			!(*only_fill = false) &&
			!(ft_strchr(VALID_WALL_MAP_CHAR, line[i])) &&
			(is_top_or_bottom ||
			(!(ft_strchr(VALID_INSIDE_MAP_CHAR, line[i])) &&
			!(*set_pl =
			(find_pl = !!(ft_strchr(VALID_PLAYER_MAP_CHAR, line[i]))) &&
			!(*set_pl)))))
			return (find_pl ? error_handler(err_too_much_player) :
			error_handler(what_is_err));
	}
	return (true);
}
