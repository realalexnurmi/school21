/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:21:10 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:21:11 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Returns TRUE (1) if character printed, else FALSE (0)
t_bool	ft_isprint(int c)
{
	if ((c >= 32) && (c <= 126))
		return (true);
	else
		return (false);
}
