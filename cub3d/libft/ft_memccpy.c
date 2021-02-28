/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:42:55 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:33:41 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*p_src;
	unsigned char	*p_dst;

	if (dst || src)
	{
		p_dst = (unsigned char *)dst;
		p_src = (unsigned char *)src;
		while (n--)
		{
			if (*p_src != (unsigned char)c)
				*p_dst++ = *p_src++;
			else
			{
				*p_dst = *p_src;
				return (++p_dst);
			}
		}
	}
	return (NULL);
}
