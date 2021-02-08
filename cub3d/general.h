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

t_retval	init_gm(t_game_master *gm, int *argc, char ***argv);
t_retval	parse_conf(t_game_master *gm, char **argv, int numarg);
#endif