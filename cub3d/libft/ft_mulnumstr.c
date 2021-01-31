/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mulnumstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 09:51:19 by enena             #+#    #+#             */
/*   Updated: 2020/12/24 06:32:59 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Function for multiply numeric string
**	Second string need eqval or less length {NOSEG}
*/

void	ft_mulnumstr(char *comp, char *mult)
{
	long long int	muln;
	size_t			len;

	muln = ft_atoll(mult);
	if (muln == 0)
	{
		len = ft_strlen(comp);
		ft_memset(comp, '0', len);
	}
	else
		while (--muln)
			ft_sumnumstr(comp, comp);
}
