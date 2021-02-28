/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:42:33 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:30:55 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns TRUE (1) if character lowercase letter, else FALSE (0)
*/

t_bool	ft_islower(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (true);
	else
		return (false);
}
