/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extention.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:19:05 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:19:06 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
t_bool	ft_check_extention(const char *name, const char *extn)
{
	if (ft_strncmp(ft_strrchr(name, '.'), extn, ft_strlen(extn) + 1))
		return (false);
	return (true);
}
