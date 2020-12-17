/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:05:26 by enena             #+#    #+#             */
/*   Updated: 2020/11/09 17:17:08 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p_srch;

	p_srch = (unsigned char*)s;
	while (n--)
	{
		if (*p_srch != (unsigned char)c)
			p_srch++;
		else
			return (p_srch);
	}
	return (NULL);
}
