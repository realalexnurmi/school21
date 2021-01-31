/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen_byte.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:52:00 by enena             #+#    #+#             */
/*   Updated: 2020/12/11 21:26:03 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function returns the required length in bytes
** to represent in a MultiByte string (UTF-8)
*/

size_t	ft_wstrlen_byte(wchar_t *wstring)
{
	size_t	len;

	len = 0;
	while (*wstring)
		len += ft_wclen(*wstring++);
	return (len);
}
