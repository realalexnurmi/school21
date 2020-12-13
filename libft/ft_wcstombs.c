/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstombs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:38:11 by enena             #+#    #+#             */
/*   Updated: 2020/12/13 00:57:14 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function returns a pointer to the allocated multibyte string
** converted from a wide character string.
*/

char	*ft_wcstombs(wchar_t *wstring)
{
	char	*s;
	char	*ret;

	if (!(s = ft_calloc(ft_wstrlen_byte(wstring) + 1, sizeof(char))))
		return (NULL);
	ret = s;
	while (*wstring)
	{
		s = ft_wctomb(*wstring, s);
		s += ft_wclen(*wstring);
		wstring++;
	}
	return (ret);
}
