/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:42:33 by enena             #+#    #+#             */
/*   Updated: 2020/12/11 21:31:44 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns TRUE (1) if character lowercase letter, else FALSE (0)
*/

t_bool	ft_islower(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (TRUE);
	else
		return (FALSE);
}
