/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_charcount.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:59:53 by enena             #+#    #+#             */
/*   Updated: 2020/12/14 23:09:57 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns count UTF-8 character in [cnt_byte] bytes.
*/

size_t		ft_get_charcount(size_t cnt_byte, char *mbs)
{
	size_t	cnt_char;
	size_t	mblen;

	cnt_char = 0;
	while ((cnt_byte) && (*mbs))
	{
		mblen = ft_mblen(mbs);
		if (mblen > cnt_byte)
			return (cnt_char);
		cnt_byte -= mblen;
		cnt_char++;
		mbs = ft_took_next_char(mbs);
	}
	return (cnt_char);
}
