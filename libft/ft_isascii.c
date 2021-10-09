/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:21:00 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:21:01 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Returns TRUE (1) if character in ASCII, else FALSE (0)
t_bool	ft_isascii(int c)
{
	if ((c >= 0) && (c <= 127))
		return (true);
	else
		return (false);
}
