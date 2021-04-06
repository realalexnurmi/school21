/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:40:07 by enena             #+#    #+#             */
/*   Updated: 2020/11/11 02:38:27 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *s, size_t maxlen)
{
	size_t	srclen;

	srclen = ft_strlen(s);
	return ((srclen < maxlen) ? srclen : maxlen);
}

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		srclen;
	size_t		dstlen;

	if ((!dst) && (!src))
		return (0);
	srclen = ft_strlen(src);
	dstlen = ft_strnlen(dst, dstsize);
	if (dstlen == dstsize || dstsize == 0)
		return (dstsize + srclen);
	if (srclen < dstsize - dstlen)
		ft_memcpy(dst + dstlen, src, srclen + 1);
	else
	{
		ft_memcpy(dst + dstlen, src, dstsize - dstlen);
		dst[dstsize - 1] = '\0';
	}
	return (dstlen + srclen);
}
