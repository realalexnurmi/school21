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

#include "cub3d.h"

t_retval	init_gm(t_game_master *gm, int *argc, char ***argv)
{
	t_retval	tmp_error;
	t_settings	linker;
	int			numarg;

	numarg = 0;
	if (tmp_error = init_settings_linker(gm, &linker))
		return (tmp_error);
	if (*argc > 1)
		while (numarg++ < argc)
		{
			if (numarg == 1)
			{
				if (tmp_error = parse_conf(gm, &linker, &((*argv)[numarg])))
					return(tmp_error);
			}
			else if (tmp_error = flag(gm, &numarg, argc, argv)
				return(tmp_error);
		}
	else
		return (ERR_MISSING_CONF);
	leave_settings_linker(linker);
	return (ALL_RIGHT);
}

t_retval	init_settings_linker(t_game_master *gm, t_settings *sl)
{
	sl->all_set = FALSE;
	sl->setting = NULL;
	if (!(sl->setting = malloc(CNT_SETTING * sizeof(t_setting_link))))
		return (ERR_ALLOC_FAIL);
	sl->setting[RESOLUTION] = get_setting_link("R", &gm->res, &set_resolution);
	sl->setting[NO_TEXTURE] = get_setting_link("NO", //&gm->res, &set_texture);
	sl->setting[SO_TEXTURE] = get_setting_link("SO", //&gm->res, &set_texture);
	sl->setting[WE_TEXTURE] = get_setting_link("WE", //&gm->res, &set_texture);
	sl->setting[EA_TEXTURE] = get_setting_link("EA", //&gm->res, &set_texture);
	sl->setting[S_TEXTURE] = get_setting_link("S", //&gm->res, &set_texture);
	sl->setting[FLOOR_COLOR] = get_setting_link("F", //&gm->res, &set_color);
	sl->setting[CEIL_COLOR] = get_setting_link("C", //&gm->res, &set_color);
	return (ALL_RIGHT);
}

t_retval	parse_conf(t_game_master *gm, t_settings *sl, char **argv)
{
	t_bool		lastline;
	t_retval	tmp_error;
	int			fd;
	int			retgnl;
	char		*line;

	if (ft_strncmp(ft_strrchr(*argv, '.'), CONF_EXTN, ft_strlen(CONF_EXTN)))
		return (ERR_BAD_EXTENTION_CONF);
	lastline = FALSE;
	line = NULL;
	if ((fd = open(*argv, O_RDONLY)) < 0)
		return (ERR_OPEN_FAIL);
	while (((retgnl = ft_get_next_line(fd, &line)) > 0) || 
				lastline = (!(lastline) && (retgnl == 0)))
	{
		if (tmp_error = analyze(gm, sl, line))
			return (tmp_error);
		line = ft_sec_free(line);
	}
	line = ft_sec_free(line);
	if (retgnl)
		return (ERR_READ_FAIL);
	return (ALL_RIGHT);
}

t_retval	analyze(t_game_master *gm, char *line)
{
	char		**tab_line;

	tab_line = NULL;
	if (!(tab_line = ft_split(line, ' ')))
		return (ERR_ALLOC_FAIL);
	if (tab_line[0])
	{
		if (ft_strlen(tab_line[0]) > 2)
			return (ERR_INCORECT_NAME_SETTING);
	}
	tab_line = ft_free_tab(tab_line);
}