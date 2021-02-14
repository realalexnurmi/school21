/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 05:13:40 by enena             #+#    #+#             */
/*   Updated: 2021/02/04 05:13:47 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H
# include "libft.h"
# include "defines.h"
# include "structs.h"
# include "error_handling.h"
# include <fcntl.h>

t_bool	init_gm(t_game_master *gm, int *argc, char ***argv);
t_bool	parse_conf(t_game_master *gm, t_settings *sl, char **argv);
t_bool	init_settings_linker(t_game_master *gm, t_settings *sl);
t_bool	parse_conf(t_game_master *gm, t_settings *sl, char **argv);
t_bool	analyze(t_game_master *gm, char *line);
#endif