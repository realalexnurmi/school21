/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmemdouble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:27:02 by enena             #+#    #+#             */
/*   Updated: 2020/12/25 10:40:53 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_binary_d	ft_getmemdouble(double dnum, char **a, char **b, char **c, char** d)
{
	t_binary_d	mem;

	ft_memcpy(&mem.mant, &dnum, 8);
	mem.sign = (mem.mant >> 63) & 0x0000000000000001;
	mem.exp = ((mem.mant >> 52) & 0x00000000000007ff) - 1023;
	mem.mant &= 0x000fffffffffffff;
	if (mem.exp != -1023 && mem.exp <= 0)
		mem.mant |= 0x0010000000000000;
	*a = NULL;
	*b = NULL;
	*c = NULL;
	*d = NULL;
	return (mem);
}
