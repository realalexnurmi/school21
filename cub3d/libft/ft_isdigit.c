/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:39:07 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:30:44 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns TRUE (1) if character digit, else FALSE (0)
*/

t_bool	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (true);
	else
		return (false);
}
