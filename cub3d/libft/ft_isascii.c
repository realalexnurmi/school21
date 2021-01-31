/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:47:20 by enena             #+#    #+#             */
/*   Updated: 2020/12/11 21:33:32 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns TRUE (1) if character in ASCII, else FALSE (0)
*/

t_bool	ft_isascii(int c)
{
	if ((c >= 0) && (c <= 127))
		return (TRUE);
	else
		return (FALSE);
}
