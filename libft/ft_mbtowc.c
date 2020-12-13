/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mbtowc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 22:45:37 by enena             #+#    #+#             */
/*   Updated: 2020/12/13 09:05:34 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** Convert MultiByte (UTF-8) to Wide Char wchar_t (32b) ~ wint_t
*/
wchar_t	ft_mbtowc(char *c)
{
	wint_t	num;
	char	i;

	num = 0;
	if (!(*c & 0x80))
		return ((wchar_t)(*c));
	i = 0;
	while (*c & 0x80)
	{
		*c <<= 1;
		i++;
	}
	*c >>= i;
	if (--i)
	{
		num = *c & ((0x40 >> i) - 1);
		while (i--)
		{
			num <<= 6;
			c++;
			num |= (*c & 0x3F);
		}
	}
	return ((wchar_t)num);
}
