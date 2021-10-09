/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:25:52 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:25:53 by enena            ###   ########.fr       */
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
		substr = ft_calloc(1, sizeof(char));
		if (!(substr))
			return (NULL);
		return (substr);
	}
	sublen = sublen - start;
	sublen = (sublen > len) * len + !(sublen > len) * sublen;
	substr = ft_calloc(sublen + 1, sizeof(char));
	if (!(substr))
		return (NULL);
	while (sublen--)
		substr[sublen] = s[start + sublen];
	return (substr);
}
