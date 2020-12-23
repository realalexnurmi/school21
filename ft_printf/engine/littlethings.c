/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   littlethings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:08:39 by enena             #+#    #+#             */
/*   Updated: 2020/12/22 18:10:29 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_nullstr(void)
{
	char *ret;

	ret = ft_calloc(7, sizeof(char));
	ft_memcpy(ret, "(null)", 6);
	return (ret);
}

void	ft_takesign(char *sign, char *anum)
{
	*sign = *anum;
	*anum = '0';
}

void	ft_addsign(char sign, char *anum)
{
	while (!(ft_isdigit(*anum)))
		anum++;
	*anum = sign;
}
