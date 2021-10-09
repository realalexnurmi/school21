/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:22:55 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:22:58 by enena            ###   ########.fr       */
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
