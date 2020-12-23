/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pownumstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:21:13 by enena             #+#    #+#             */
/*   Updated: 2020/12/23 12:37:31 by enena            ###   ########.fr       */
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
	else if (pow > 0)
	{
		if (!(rez = ft_strdup(base)))
			return (NULL);
		while (pow--)
			ft_mulnumstr(rez, base);
		return (rez);
	}
	return (base);
}
