/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naming_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:14:55 by enena             #+#    #+#             */
/*   Updated: 2021/02/10 18:15:00 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "naming_utils.h"

static t_bool	name_resolution(char **filename, int value)
{
	char	*value_str;
	char	*tmp;

	value_str = ft_lltoa_base(value, BASE_10);
	tmp = *filename;
	if (!(*filename = ft_strjoin(*filename, "_")))
		return (error_handler(err_alloc_fail));
	tmp = ft_sec_free(tmp);
	tmp = *filename;
	if (!(*filename = ft_strjoin(*filename, value_str)))
		return (error_handler(err_alloc_fail));
	tmp = ft_sec_free(tmp);
	value_str = ft_sec_free(value_str);
	return (true);
}

t_bool		add_name_image_resolution(char **filename, t_image *data)
{
	if (!(name_resolution(filename, data->width)))
		return (false);
	if (!(name_resolution(filename, data->height)))
		return (false);
	return (true);
}


