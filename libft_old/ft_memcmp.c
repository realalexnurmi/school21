/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:27:00 by enena             #+#    #+#             */
/*   Updated: 2020/11/07 15:54:34 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	cntr;

	cntr = 0;
	if (s1 || s2)
	{
		while (cntr < n)
		{
			if (((unsigned char *)s1)[cntr]
					!= ((unsigned char *)s2)[cntr])
			{
				return (((unsigned char *)s1)[cntr]
						- ((unsigned char *)s2)[cntr]);
			}
			cntr++;
		}
	}
	return (0);
}
