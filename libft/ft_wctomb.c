/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:37:23 by enena             #+#    #+#             */
/*   Updated: 2020/12/14 18:22:35 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function converts a wide character [src] to MultiByte representation
** and writes to destination string [dest] using ft_memcpy.
** Using ft_wclen determines how many [wln] octets to use for the presentation.
** UTF-8:
** First octet:	wln == 1 	0b0XXXXXXX	\
**				wln == 2	0b110XXXXX	|
**				wln == 3 	0b1110XXXX	|-> where X stores value [num]
**				wln == 4	0b11110XXX	|
** Second - fourth oct's: 	0b10XXXXXX	/
** Returns the number of copied bytes.
*/

char	*ft_wctomb(wchar_t src, char *dest)
{
	unsigned char	oct[4];
	wint_t			num;
	size_t			wln;

	ft_bzero(oct, 4);
	num = (wint_t)src & 0x7FFFFFFF;
	wln = ft_wclen(src);
	if (!(wln))
		return (NULL);
	oct[0] = ((0xF0 << ((4 - wln) + (wln == 1))) |
			(((0x7F >> (wln - (wln == 1)))) & (char)(num >> 6 * (wln - 1))));
	oct[1] = (wln < 2) ? oct[1] :
		((0x3F & (char)((num >> 6 * (wln - 2)) & 0x000000FF)) | 0x80);
	oct[2] = (wln < 3) ? oct[2] :
		((0x3F & (char)((num >> 6 * (wln - 3)) & 0x000000FF)) | 0x80);
	oct[3] = (wln < 4) ? oct[3] :
		((0x3F & (char)(num & 0x000000FF)) | 0x80);
	dest = ft_memcpy(dest, &(oct[0]), wln);
	return (dest);
}
