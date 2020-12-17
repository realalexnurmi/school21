/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:33:02 by enena             #+#    #+#             */
/*   Updated: 2020/11/09 15:00:10 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrchr(const void *s, int c, size_t n)
{
	unsigned char *p_srch;

	p_srch = (unsigned char*)s;
	while (n--)
	{
		if (*p_srch != (unsigned char)c)
			p_srch--;
		else
			return (p_srch);
	}
	return (NULL);
}

char		*ft_strrchr(const char *s, int c)
{
	size_t	st_len;

	st_len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)(s + st_len));
	else
		return ((char *)ft_memrchr((s + st_len - 1), c, st_len));
}
