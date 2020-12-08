/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 02:06:19 by enena             #+#    #+#             */
/*   Updated: 2020/11/10 20:32:07 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	ft_countdgt(int n)
{
	unsigned char	cnt;

	cnt = 0;
	if (n <= 0)
		cnt++;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char					*ft_itoa(int n)
{
	char			*s;
	unsigned char	cnt;

	cnt = ft_countdgt(n);
	if (!(s = ft_calloc((cnt + 1), sizeof(char))))
		return (NULL);
	if (n < 0)
		*s = '-';
	while (cnt-- > (*s == '-'))
	{
		s[cnt] = (n < 0 ? -(n % 10) : n % 10) + '0';
		n /= 10;
	}
	return (s);
}
