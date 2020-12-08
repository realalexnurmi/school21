/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:08:14 by enena             #+#    #+#             */
/*   Updated: 2020/11/09 23:46:28 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			slen;
	unsigned int	start;

	if (!s1)
		return (NULL);
	slen = ft_strlen(s1);
	if (!set || !(*set))
		return (ft_substr(s1, 0, slen));
	start = 0;
	while (s1[start] && ft_strchr(set, (int)(s1[start])))
	{
		start++;
		slen--;
	}
	while (slen && ft_strchr(set, (int)(s1[slen + start])))
		slen--;
	return (ft_substr(s1, start, slen + 1));
}
