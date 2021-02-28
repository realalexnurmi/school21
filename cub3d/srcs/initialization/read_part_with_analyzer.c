/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_part_with_analyzer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:21:46 by enena             #+#    #+#             */
/*   Updated: 2021/02/28 11:15:06 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

/*
** Function reading and analyze with analyzer function
*/

t_bool	read_part(void *part, const int fd,
									char **line, const t_analyzer analyzer)
{
	int			retgnl;
	t_bool		lastline_drop;

	lastline_drop = false;
	while (((retgnl = ft_get_next_line(fd, line)) > 0) ||
			(lastline_drop = (!(lastline_drop) && (retgnl == 0))))
	{
		if (!(analyzer(part, *line, &lastline_drop)))
		{
			if (!(lastline_drop))
				*line = ft_sec_free(*line);
			return (lastline_drop);
		}
		*line = ft_sec_free(*line);
	}
	*line = ft_sec_free(*line);
	if (retgnl)
		return (error_handler(err_read_fail));
	return (true);
}

/*
** Analyzer for setting line
*/

t_bool	analyze_setting(void *psettings, const char *line, t_bool *ll_dr)
{
	char		**tab_line;
	ssize_t		i;
	t_bool		retset;
	t_settings	*stngs;

	stngs = psettings;
	if (*ll_dr)
		return (*ll_dr = error_handler(err_missing_map));
	if (!(*line))
		return (true);
	tab_line = NULL;
	if (!(tab_line = ft_split(line, ' ')))
		return (error_handler(err_alloc_fail));
	i = -1;
	retset = false;
	while (++i < CNT_SETTING)
		if (!(ft_strncmp(stngs->link[i].idntf, *tab_line, SIZE_IDNTF_SETTING)))
		{
			retset = stngs->link[i].set(&(stngs->link[i]), tab_line);
			tab_line = ft_free_tab(tab_line);
			return (retset);
		}
	*ll_dr = true;
	tab_line = ft_free_tab(tab_line);
	return (false);
}

/*
** Analyzer for reading in list map
*/

t_bool	analyze_map(void *pmap, const char *line, t_bool *ll_dr)
{
	t_map	*map;
	t_bool	only_fill;

	if (!(*line))
		return (*ll_dr = error_handler(err_empty_line_in_map));
	map = pmap;
	only_fill = true;
	if (!(check_junk(line, *ll_dr ? err_last_line_map : err_middle_line_map,
						&map->player_set, &only_fill)))
		return (*ll_dr = false);
	if (!only_fill)
		if (!(add_map_line_to_list(map->tmp, line)))
			return (*ll_dr = false);
	return (true);
}
