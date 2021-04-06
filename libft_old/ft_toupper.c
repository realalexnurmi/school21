/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:41:23 by enena             #+#    #+#             */
/*   Updated: 2020/12/11 20:38:54 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** If [c] represents an lowercase letter,
** and there exists a corresponding uppercase letter.
** All other arguments in the domain are returned unchanged.
** Only "C" locale.
*/

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c + ('A' - 'a'));
	else
		return (c);
}
