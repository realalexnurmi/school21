/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_part_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 03:21:47 by enena             #+#    #+#             */
/*   Updated: 2021/02/04 03:21:49 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

t_bool	init_gm(t_game_master *gm, int *argc, char ***argv)
{
	t_settings	linker;
	int			numarg;

	numarg = 0;
	if (!(init_settings_linker(gm, &linker)))
		return (false);
	if (*argc > 1)
		while (numarg++ < *argc)
		{
			if (numarg == 1)
			{
				if (!(parse_conf(gm, &linker, &((*argv)[numarg]))))
					return (false);
			}
			// else if (!(flag(gm, &numarg, argc, argv)))
			// 	return (false);
		}
	else
		return (error_handler(err_missing_conf));
	//leave_settings_linker(linker);
	return (true);
}

t_bool	init_settings_linker(t_game_master *gm, t_settings *sl)
{
	sl->all_set = false;
	sl->setting = NULL;
	if (!(sl->setting = malloc(CNT_SETTING * sizeof(t_setting_link))))
		return (error_handler(err_alloc_fail));
	// sl->setting[RESOLUTION] = get_setting_link("R", &gm->res, &set_resolution);
	// sl->setting[NO_TEXTURE] = get_setting_link("NO", //&gm->res, &set_texture);
	// sl->setting[SO_TEXTURE] = get_setting_link("SO", //&gm->res, &set_texture);
	// sl->setting[WE_TEXTURE] = get_setting_link("WE", //&gm->res, &set_texture);
	// sl->setting[EA_TEXTURE] = get_setting_link("EA", //&gm->res, &set_texture);
	// sl->setting[S_TEXTURE] = get_setting_link("S", //&gm->res, &set_texture);
	// sl->setting[FLOOR_COLOR] = get_setting_link("F", //&gm->res, &set_color);
	// sl->setting[CEIL_COLOR] = get_setting_link("C", //&gm->res, &set_color);
	return (true);
}

t_bool	parse_conf(t_game_master *gm, t_settings *sl, char **argv)
{
	t_bool		lastline;
	int			fd;
	int			retgnl;
	char		*line;

	if (ft_strncmp(ft_strrchr(*argv, '.'), CONF_EXTN, ft_strlen(CONF_EXTN)))
		return (error_handler(err_bad_extention_conf));
	lastline = false;
	line = NULL;
	if ((fd = open(*argv, O_RDONLY)) < 0)
		return (error_handler(err_open_read_fail));
	while (((retgnl = ft_get_next_line(fd, &line)) > 0) || 
				(lastline = (!(lastline) && (retgnl == 0))))
	{
		if (!(analyze(gm, line)))
			return (false);
		line = ft_sec_free(line);
	}
	line = ft_sec_free(line);
	if (retgnl)
		return (error_handler(err_read_fail));
	return (true);
}

t_bool	analyze(t_game_master *gm, char *line)
{
	char		**tab_line;

	tab_line = NULL;
	if (!(tab_line = ft_split(line, ' ')))
		return (error_handler(err_alloc_fail));
	if (tab_line[0])
	{
		if (ft_strlen(tab_line[0]) > 2)
			return (error_handler(err_incorect_name_setting));
	}
	tab_line = ft_free_tab(tab_line);
	return (true);
}