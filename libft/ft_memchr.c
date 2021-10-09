/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:21:51 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:21:52 by enena            ###   ########.fr       */
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
