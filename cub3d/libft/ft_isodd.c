/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isodd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:42:48 by enena             #+#    #+#             */
/*   Updated: 2020/12/24 14:47:31 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isodd(int c)
{
	if ((c == '1') || (c == '3') || (c == '5') || (c == '7') || (c == '9'))
		return (true);
	else
		return (false);
}
