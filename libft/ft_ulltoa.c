/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 02:36:37 by enena             #+#    #+#             */
/*   Updated: 2020/12/15 03:04:45 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa(t_ullint n)
{
	char		*s;
	size_t		cnt;
	t_ullint	copy

	cnt = 0;
	copy = n;
	if (copy = 0)
		cnt++;
	while (copy)
	{
		copy /= 10;
		cnt++;
	}
	if (!(s = ft_calloc((cnt + 1), sizeof(char))))
		return (NULL);
	while (cnt--)
	{
		s[cnt] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}
