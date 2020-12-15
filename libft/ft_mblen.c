/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:19:32 by enena             #+#    #+#             */
/*   Updated: 2020/12/15 01:04:44 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Look UTF-8 info first byte MultiByte and returns length in byte character
*/

size_t	ft_mblen(char *mbc)
{
	size_t	count_one;
	char	copy;

	count_one = 0;
	copy = *mbc;
	while (copy & 0x80)
	{
		copy <<= 1;
		count_one++;
	}
	if (count_one == 0)
		return (1);
	else
		return ((count_one == 1 || count_one > 4) ? 0 : count_one);
}
