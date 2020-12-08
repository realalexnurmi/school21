/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:53:24 by enena             #+#    #+#             */
/*   Updated: 2020/11/07 16:01:40 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	s_minlen_n;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if ((s1_len == 0) || (s2_len == 0))
	{
		if (((s1_len == 0) && (s2_len == 0)) || (!n))
			return (0);
		else
			return (s1_len == 0 ? -1 : 1);
	}
	s_minlen_n = (s1_len < n ? s1_len + 1 : n);
	s_minlen_n = (s2_len < n ? s2_len + 1 : n);
	return (ft_memcmp(s1, s2, s_minlen_n));
}
