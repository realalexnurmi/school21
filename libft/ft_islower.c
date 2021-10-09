/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:21:06 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:21:07 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Returns TRUE (1) if character lowercase letter, else FALSE (0)
t_bool	ft_islower(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (true);
	else
		return (false);
}
