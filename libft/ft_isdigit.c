/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:21:02 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:21:03 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Returns TRUE (1) if character digit, else FALSE (0)
t_bool	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (true);
	else
		return (false);
}
