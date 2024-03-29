/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_linker_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 11:37:29 by enena             #+#    #+#             */
/*   Updated: 2021/03/14 00:22:09 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

/*
** Adjusts the {link} according to the passed parameters
** {idntf} - first type information -> expected identifier
** {cnt_fields} - count type information in setting line
** {setter} - pointer to a function that sets the setting value
*/

static void	init_setting_link(t_setting_link *link, const char *idntf,
						const size_t cnt_fields, const t_set_setting setter)
{
	link->is_set = false;
	link->cnt_fields = cnt_fields;
	ft_strlcpy(link->idntf, idntf, SIZE_IDNTF_SETTING);
	link->set = setter;
	link->get = NULL;
}

/*
** Combining link initializations into a block
** Contain 8 init_setting_link() for (0 - 7) [enum e_setting_name]
**	resolution
**	no_texture
**	so_texture
**	we_texture
**	ea_texture
** 	s_texture
**	floor_color
**	ceil_color
*/

static void	init_links_group_1(t_setting_link *links)
{
	init_setting_link(&links[resolution], "R", 3, &set_resolution);
	init_setting_link(&links[no_texture], "NO", 2, &set_texture);
	init_setting_link(&links[so_texture], "SO", 2, &set_texture);
	init_setting_link(&links[we_texture], "WE", 2, &set_texture);
	init_setting_link(&links[ea_texture], "EA", 2, &set_texture);
	init_setting_link(&links[s_texture], "S", 2, &set_texture);
	init_setting_link(&links[floor_color], "F", 2, &set_color);
	init_setting_link(&links[ceil_color], "C", 2, &set_color);
}

/*
** Allocates memory for the structure of links to settings
** and performs initialization (count=[CNT_SETTING]) links
*/

t_bool		init_settings_linker(t_settings **settings, t_game_master *bl)
{
	ssize_t		i;
	t_settings	*tmp;

	tmp = *settings;
	if (!(tmp = malloc(sizeof(t_settings))))
		return (error_handler(err_alloc_fail));
	tmp->is_all_set = false;
	tmp->link = NULL;
	if (!(tmp->link = malloc((CNT_SETTING) * sizeof(t_setting_link))))
		return (error_handler(err_alloc_fail));
	i = -1;
	init_links_group_1(tmp->link);
	while (++i < CNT_SETTING)
		tmp->link[i].backlink = bl;
	*settings = tmp;
	return (true);
}
