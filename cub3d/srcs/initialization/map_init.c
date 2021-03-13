/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:24:57 by enena             #+#    #+#             */
/*   Updated: 2021/03/11 01:39:36 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

static void	map_setup(t_map *map)
{
	map->player_set = false;
	map->yx = NULL;
	map->mx_y = 0;
	map->mx_x = 0;
	map->count_sprite = 0;
	map->tmp->bgn_ind = 0;
	map->tmp->end_ind = 0;
	map->tmp->len = 0;
	map->tmp->listsize = 0;
	map->tmp->list = NULL;
}

t_bool		init_map(t_map **map, char **line)
{
	t_bool	only_fill;

	if (!((*map) = malloc(sizeof(t_map))) ||
		!((*map)->tmp = malloc(sizeof(t_map_list))))
	{
		*line = ft_sec_free(*line);
		return (error_handler(err_alloc_fail));
	}
	map_setup(*map);
	only_fill = true;
	if (!(check_junk(*line, err_first_line_map,
			&(*map)->player_set, &only_fill)))
	{
		*line = ft_sec_free(*line);
		return (false);
	}
	if (!only_fill)
		if (!(add_map_line_to_list((*map)->tmp, *line)))
		{
			*line = ft_sec_free(*line);
			return (false);
		}
	*line = ft_sec_free(*line);
	return (true);
}

static void	took_param(const char *base, t_map_list *ml)
{
	const char	*bgn;
	const char	*end;
	size_t		calc_bgn_ind;
	size_t		calc_end_ind;

	bgn = base;
	end = base + ft_strlen(base) - 1;
	while (ft_strchr(VALID_FILL_MAP_CHAR, *bgn))
		++bgn;
	while (ft_strchr(VALID_FILL_MAP_CHAR, *end))
		--end;
	calc_bgn_ind = bgn - base;
	calc_end_ind = end - base;
	if (ml->listsize)
	{
		ml->bgn_ind = ml->bgn_ind < calc_bgn_ind ? ml->bgn_ind : calc_bgn_ind;
		ml->end_ind = ml->end_ind > calc_end_ind ? ml->end_ind : calc_end_ind;
	}
	else
	{
		ml->bgn_ind = calc_bgn_ind;
		ml->end_ind = calc_end_ind;
	}
	ml->len = ml->end_ind - ml->bgn_ind + 1;
}

t_bool		add_map_line_to_list(t_map_list *ml, const char *map_line)
{
	char	*content;
	t_list	*new;

	if (!(content = ft_strdup(map_line)))
		return (error_handler(err_alloc_fail));
	if (!(new = ft_lstnew(content)))
	{
		content = ft_sec_free(content);
		return (error_handler(err_alloc_fail));
	}
	took_param(content, ml);
	++(ml->listsize);
	ft_lstadd_back(&ml->list, new);
	return (true);
}

/*
** My garbage check function at the line reading stage. Check string {line}.
** @The type of check is determined depending on the transmitted error
** {what_is_err} and set in {is_top_or_bottom}.
** Top or bottom line maps are checked only for fill or wall symbols.
** Otherwise, an error.
** On going from checking padding characters onwards,
** the outer flag {only_fill} is set to false.
** If the flag is false, the check continues
** for valid characters inside the map, excluding the player characters.
** The player's symbol is assumed to be the only one in the entire map.
** Therefore, even when the character is determined as a player and
** the flag {find_pl} is set, whether or not the outer flag {set_pl}
** is set to the player is considered.
** Which causes the repeated player symbol error. [err_too_much_player]
** It work in one if into while.
** Returns true if no garbage was found and
** an error handler was called with the passed error
** or too many player error if this case was handled.
*/

t_bool		check_junk(const char *line, const t_error what_is_err,
											t_bool *set_pl, t_bool *only_fill)
{
	ssize_t			i;
	t_bool			find_pl;
	t_bool			is_top_or_bottom;

	is_top_or_bottom =
	(what_is_err == err_first_line_map || what_is_err == err_last_line_map) ?
	true : false;
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
			return (find_pl ?
			error_handler(err_too_much_player) :
			error_handler(what_is_err));
	}
	return (true);
}
