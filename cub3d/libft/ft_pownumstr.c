/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pownumstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:21:13 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:34:24 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Function for exponentiation numeric string
**	Second argument convert to long long int - meh - rework it {NOSEG}
*/

char	*ft_pownumstr(char *base, char *pow)
{
	long long int	pown;
	size_t			len;
	char			*rez;

	pown = ft_atoll(pow);
	if (pown == 0)
	{
		len = ft_strlen(base);
		ft_memset(base, '0', len);
		base[len - 1] = '1';
		return (base);
	}
	else if (pown > 0)
	{
		if (!(rez = ft_strdup(base)))
			return (NULL);
		while (--pown)
		{
			ft_mulnumstr(rez, base);
		}
		free(base);
		return (rez);
	}
	return (base);
}
