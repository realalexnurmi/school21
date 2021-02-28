/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extention.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 01:34:34 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 01:37:56 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_check_extention(const char *name, const char *extn)
{
	if (ft_strncmp(ft_strrchr(name, '.'), extn, ft_strlen(extn)))
		return (false);
	return (true);
}