/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:42:20 by enena             #+#    #+#             */
/*   Updated: 2021/03/09 07:12:36 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZATION_H
# define INITIALIZATION_H

# include "libft.h"
# include "defines.h"
# include "structs.h"
# include "general.h"
# include "error_handling.h"
# include "mlx.h"
# include <fcntl.h>

/*
** File: game_master_init
** Initialization of the main structure by the passed arguments to the program:
** ->Parsing the first as a file with the extension .cub
** 	and the specified settings for the subject
** ->Parsing flags as subsequent parameters
*/

t_bool	init_gm(t_game_master *gm, const int argc, char **argv);
t_bool	parse_conf(t_game_master *gm, const char *argv);
t_bool	take_flag();
/*
** Type pointer to function analyzer getted line. Use in read_part().
*/
typedef t_bool	(*t_analyzer)(void *, const char *line, t_bool *);
/*
** File: read_part_with_analyzer
** Function for processing different parts of a file in the same type.
** Reads with get_next_line() and use {t_analyzer} on getted line.
*/

t_bool	read_part(void *part, const int fd, char **line,
													const t_analyzer analyzer);
t_bool	analyze_setting(void *psettings, const char *line, t_bool *ll_dr);
t_bool	analyze_map(void *pmap, const char *line, t_bool *ll_dr);
/*
** File: settings_linker_init
** Group of functions for initializing the storage
** structure of links to configurable parameters
*/

t_bool	init_settings_linker(t_settings **settings, t_game_master *bl);
/*
** File: setters_settings
*/

t_bool	set_resolution(void *plink, char **tab);
t_bool	set_texture(void *plink, char **tab);
t_bool	set_color(void *plink, char **tab);
/*
** File: map_init
*/

t_bool	init_map(t_map **map, char **line);
t_bool	add_map_line_to_list(t_map_list *ml, const char *map_line);
t_bool	check_junk(const char *line, const t_error what_is_err,
									t_bool *set_pl, t_bool *only_fill);
/*
** File: map_convert_utils
*/

t_bool	convert_map_player_init(t_map *map, t_player **pl);
/*
** File: images
*/

t_image	*get_image(void *img, int width, int height);
t_bool	make_frame(t_game_master *gm);
t_bool	open_window(t_game_master *gm);

/*
** File: keys_init
*/

t_bool	keys_init(t_keys **keys);
void	init_keys_group_1(t_key *keys);

t_bool	render_init(t_game_master *gm);

#endif
