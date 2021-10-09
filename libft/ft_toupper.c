/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:26:06 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:26:07 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// If [c] represents an lowercase letter,
// and there exists a corresponding uppercase letter.
// All other arguments in the domain are returned unchanged.
int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c + ('A' - 'a'));
	else
		return (c);
}
