/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naming_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:59:33 by enena             #+#    #+#             */
/*   Updated: 2021/03/09 07:23:18 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMING_UTILS_H
# define NAMING_UTILS_H
# include "libft.h"
# include "defines.h"
# include "structs.h"
# include "error_handling.h"

t_bool	add_name_image_resolution(char **filename, t_image *data);
t_bool	put_name_screenshot(char **dst, const char *map, t_image *data);

#endif
