/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:43:40 by enena             #+#    #+#             */
/*   Updated: 2020/12/11 21:35:08 by enena            ###   ########.fr       */
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
		return (TRUE);
	else
		return (FALSE);
}
