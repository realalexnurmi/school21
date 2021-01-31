/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:50:00 by enena             #+#    #+#             */
/*   Updated: 2020/10/30 19:00:34 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p_tmp;

	p_tmp = (unsigned char*)b;
	while (len--)
	{
		*p_tmp = (unsigned char)c;
		p_tmp++;
	}
	return (b);
}
