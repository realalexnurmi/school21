/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:43:40 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:31:44 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns TRUE (1) if character printed, else FALSE (0)
** Only "C" locale.
*/

t_bool	ft_isprint(int c)
{
	if ((c >= 32) && (c <= 126))
		return (true);
	else
		return (false);
}
