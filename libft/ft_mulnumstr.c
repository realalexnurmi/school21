/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mulnumstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 09:51:19 by enena             #+#    #+#             */
/*   Updated: 2020/12/23 12:42:57 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Function for multiply numeric string
**	Second string need eqval or less length {NOSEG}
*/

void	ft_mulnumstr(char *comp, char *mult)
{
	size_t	min;
	char	trans;

	comp += ft_strlen(comp) - 1;
	min = ft_strlen(mult);
	mult += min - 1;
	trans = 0;
	while (min-- || trans)
	{
		if (min)
			*comp = (*comp - '0') * (*mult - '0') + '0';
		*comp += trans;
		trans = 0;
		if (*comp - '0' > 10)
		{
			trans = (*comp - '0') / 10;
			*comp -= trans * 10;
		}
		comp--;
		if (min)
			mult--;
	}
}
