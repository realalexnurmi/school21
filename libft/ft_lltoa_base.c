/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 04:03:12 by enena             #+#    #+#             */
/*   Updated: 2020/12/15 04:10:58 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa_base(long long int n, t_uchar base)
{
	const char		digit[17] = "0123456789abcdef";
	char			*s;
	size_t			cnt;
	long long int	copy;

	if ((base == 0) || (base == 1) || (base > 16))
		return (NULL);
	cnt = (n < 0) ? 2 : 1;
	copy = n;
	while (copy /= base)
		cnt++;
	if (!(s = ft_calloc((cnt + 1), sizeof(char))))
		return (NULL);
	if (n < 0)
	{
		*s = '-';
		n = ~(n - 1);
	}
	while (cnt-- > (*s == '-'))
	{
		s[cnt] = digit[(n % base)];
		n /= base;
	}
	return (s);
}
