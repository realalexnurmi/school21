/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:23:25 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:23:27 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*p_temp;
	char	search_c;
	size_t	needle_len;
	size_t	haystack_len;

	needle_len = ft_strlen(needle);
	if ((!needle_len) || (haystack == needle))
		return ((char *)haystack);
	haystack_len = ft_strlen(haystack);
	len = (len > haystack_len) * haystack_len + !(len > haystack_len) * len;
	if ((needle_len > len) || ((needle_len == len) && (*haystack != *needle)))
		return (NULL);
	search_c = (char)*needle;
	p_temp = ft_strchr(haystack, (int)search_c);
	while (p_temp && (p_temp <= &(haystack[len - needle_len])))
	{
		if (!(ft_strncmp(needle, p_temp, needle_len)))
			return (p_temp);
		p_temp++;
		p_temp = ft_strchr(p_temp, (int)search_c);
	}
	return (NULL);
}
