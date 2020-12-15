/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_size_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 04:09:32 by enena             #+#    #+#             */
/*   Updated: 2020/12/15 05:53:53 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_check_size(t_msize *size, char *s)
{
	if (*s == 'l')
		*size = (*(s - 1) == 'l') ? LL : L;
	if (*s == 'h')
		*size = (*(s - 1) == 'h') ? HH : H;
	if (*s == 'z')
		*size = Z;
}
