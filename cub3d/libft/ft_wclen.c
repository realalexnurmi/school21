/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wclen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:37:28 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:37:28 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function returns how many bytes it takes
** to represent a wide character in MultiByte string format (UTF-8)
*/

size_t	ft_wclen(wchar_t wc)
{
	wint_t	i;

	i = (wint_t)wc;
	if (i <= 0x0000007F)
		return (1);
	if (i <= 0x000007FF)
		return (2);
	if (i <= 0x0000FFFF)
		return (3);
	if (i <= 0x0010FFFF)
		return (4);
	return (0);
}
