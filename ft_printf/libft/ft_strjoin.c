/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:49:05 by enena             #+#    #+#             */
/*   Updated: 2020/11/09 21:05:11 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*js;

	if ((!s1) && (!s2))
		return (NULL);
	s1len = (s1 ? ft_strlen(s1) : 0);
	s2len = (s2 ? ft_strlen(s2) : 0);
	if (!(js = ft_calloc(s1len + s2len + 1, sizeof(char))))
		return (NULL);
	ft_strlcpy(js, (s1 ? s1 : s2), (s1 ? s1len + 1 : s2len + 1));
	if (s2)
		ft_strlcat(js, s2, s1len + s2len + 1);
	return (js);
}