/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mbtowc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 22:45:37 by enena             #+#    #+#             */
/*   Updated: 2020/12/14 23:05:52 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convert MultiByte (UTF-8) to Wide Char wchar_t (32b) ~ wint_t
*/

wchar_t	ft_mbtowc(char *mbc)
{
	wint_t	num;
	char	len;

	num = 0;
	len = ft_mblen(mbc);
	if (len == 1)
		return ((wchar_t)(*mbc));
	else if (len > 1)
	{
		num = *mbc & ((0x40 >> len) - 1);
		while (len--)
		{
			num <<= 6;
			mbc++;
			num |= (*mbc & 0x3F);
		}
		return ((wchar_t)(*mbc));
	}
	return (0);
}
