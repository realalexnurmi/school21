/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:21:21 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 17:01:37 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_ullint	dk(long long int num)
{
	if (num < 0)
		return (~num + 1);
	else
		return (num);
}

static size_t	count_char(t_ullint num, t_uchar base)
{
	size_t	cnt;

	cnt = 0;
	num /= base;
	while (num)
		cnt++;
	return (cnt);
}

char	*ft_lltoa_base(long long int n, t_uchar base)
{
	const char	digit[17] = "0123456789abcdef";
	char		*s;
	size_t		cnt;
	t_ullint	copy;

	if ((base == 0) || (base == 1) || (base > 16))
		return (NULL);
	cnt = (n < 0) + 1;
	copy = dk(n);
	cnt += count_char(copy, base);
	s = ft_calloc((cnt + 1), sizeof(char));
	if (!s)
		return (NULL);
	if (n < 0)
		*s = '-';
	while (cnt-- > (*s == '-'))
	{
		s[cnt] = digit[(copy % base)];
		copy /= base;
	}
	return (s);
}
