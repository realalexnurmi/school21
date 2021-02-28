/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:47:20 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:30:36 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns TRUE (1) if character in ASCII, else FALSE (0)
*/

t_bool	ft_isascii(int c)
{
	if ((c >= 0) && (c <= 127))
		return (true);
	else
		return (false);
}
