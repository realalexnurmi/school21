/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:03:07 by enena             #+#    #+#             */
/*   Updated: 2020/12/24 09:58:41 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	st_len;

	st_len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)(s + st_len));
	else
		return ((char *)ft_memchr(s, c, st_len));
}
