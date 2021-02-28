/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstombs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:38:11 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:37:31 by enena            ###   ########.fr       */
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
		if (!(s = ft_wctomb(*wstring, s)))
		{
			free(ret);
			return (NULL);
		}
		s += ft_wclen(*wstring);
		wstring++;
	}
	return (ret);
}
