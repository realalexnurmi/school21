/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_master_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:43:57 by enena             #+#    #+#             */
/*   Updated: 2021/03/09 06:14:58 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

/*
** Initialization all pointer of NULL
*/

static void		gm_setup(t_game_master *gm)
{
	gm->mlx = mlx_init();
	gm->name = NULL;
	gm->win = NULL;
	gm->sl = NULL;
	gm->map = NULL;
	gm->pl = NULL;
	gm->save = false;
	gm->keys = NULL;
	gm->frame = NULL;
	gm->table = NULL;
	gm->render = NULL;
}

/*
** Run initialization settings linker.
** Parse configuration from .cub file and take it on link
** and on initialization of map.
** Take next arguments as flag.
** Returns false if calling handler of errors return false deep down
** else true.
*/

t_bool			init_gm(t_game_master *gm, const int argc, char **argv)
{
	int			numarg;

	numarg = 0;
	gm_setup(gm);
	if (argc > 1)
		while (++numarg < argc)
		{
			if (numarg == 1)
			{
				if (!(parse_conf(gm, argv[numarg])))
					return (false);
			}
			else if (!(take_flag(gm, numarg, argv[numarg])))
				return (false);
		}
	else
		return (error_handler(err_missing_conf));
	if (!(make_frame(gm)))
		return (false);
	if (!(open_window(gm)))
		return (false);
	if (!(keys_init(&gm->keys)))
		return (false);
	return (true);
}

/*
** Checking that all setting finded after read part with setting
** and initialization map
*/

static t_bool	check_all_settings(t_settings *settings)
{
	ssize_t		i;

	i = -1;
	settings->is_all_set = true;
	while (++i < CNT_SETTING)
		settings->is_all_set &= settings->link[i].is_set;
	if (settings->is_all_set)
		return (true);
	else
		return (error_handler(err_missing_setting));
}

/*
** Parser for configuration file.
** Check extension .cub -> Open file -> Read part "settings" ->
** Initialization map -> Checking that all setting finded ->
** Read part "map" -> Converting map list into matrix of char.
** Close file anyway if open.
** Returns false if calling handler of errors return false deep down
** else true.
*/

t_bool			parse_conf(t_game_master *gm, const char *argv)
{
	int			fd;
	char		*line;

	if (!(ft_check_extention(argv, CONF_EXTN)))
		return (error_handler(err_bad_extention_conf));
	if (!(gm->name = ft_strjoin(BASENAME, argv)))
		return (error_handler(err_alloc_fail));
	if (!(init_settings_linker(&gm->sl, gm)))
		return (false);
	if ((fd = open(argv, O_RDONLY)) < 0)
		return (error_handler(err_open_read_fail));
	line = NULL;
	if (!(read_part(gm->sl, fd, &line, &analyze_setting)) ||
		!(init_map(&gm->map, &line)) ||
		!(check_all_settings(gm->sl)) ||
		!(read_part(gm->map, fd, &line, &analyze_map)) ||
		!(convert_map_player_init(gm->map, &gm->pl)))
	{
		if (close(fd) < 0)
			return (error_handler(err_close_fail));
		return (false);
	}
	if (close(fd) < 0)
		return (error_handler(err_close_fail));
	return (true);
}

/*
** Applying flags
*/

t_bool			take_flag(t_game_master *gm, const int num, const char *argv)
{
	const char	*flags[CNT_FLAGS] = {"--save"};
	ssize_t		i;
	t_bool		applyed;

	if (num > CNT_ARG)
		return (error_handler(err_too_much_arguments));
	i = -1;
	applyed = false;
	while (++i < CNT_FLAGS)
		if (!(ft_strncmp(flags[i], argv, ft_strlen(flags[i]) + 1)))
		{
			applyed = true;
			gm->save = (i == 0) ? true : false;
		}
	if (applyed)
		return (true);
	else
		return (error_handler(err_unknown_flag));
}
