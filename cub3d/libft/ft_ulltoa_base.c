/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 15:08:19 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:37:17 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa_base(t_ullint n, t_uchar base)
{
	const char		digit[17] = "0123456789abcdef";
	char			*s;
	size_t			cnt;
	t_ullint		copy;

	if ((base == 0) || (base == 1) || (base > 16))
		return (NULL);
	cnt = 1;
	copy = n;
	while (copy /= base)
		cnt++;
	if (!(s = ft_calloc((cnt + 1), sizeof(char))))
		return (NULL);
	while (cnt-- > 0)
	{
		s[cnt] = digit[(n % base)];
		n /= base;
	}
	return (s);
}
