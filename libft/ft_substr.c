/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:28:45 by enena             #+#    #+#             */
/*   Updated: 2020/11/12 01:00:48 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sublen;
	char	*substr;

	if (!s)
		return (NULL);
	sublen = ft_strlen(s);
	if (start >= sublen)
	{
		if (!(substr = ft_calloc(1, sizeof(char))))
			return (NULL);
		return (substr);
	}
	sublen = sublen - start;
	sublen = (sublen > len) ? len : sublen;
	if (!(substr = ft_calloc(sublen + 1, sizeof(char))))
		return (NULL);
	while (sublen--)
		substr[sublen] = s[start + sublen];
	return (substr);
}
