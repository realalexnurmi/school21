/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_sign_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 03:26:20 by enena             #+#    #+#             */
/*   Updated: 2020/12/26 03:33:47 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool		take_g_sign(double *fnum)
{
	t_ullint	mem;
	t_bool		ret;

	ft_memcpy(&mem, fnum, 8);
	ret = !!(mem & 0x8000000000000000);
	mem &= 0x7fffffffffffffff;
	ft_memcpy(fnum, &mem, 8);
	return (ret);
}
