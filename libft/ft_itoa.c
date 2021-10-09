/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:21:17 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:37:31 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_itoa(int n)
{
	char	*s;
	size_t	cnt;
	int		copy;

	cnt = 0;
	copy = n;
	if (copy <= 0)
		cnt++;
	while (copy)
	{
		copy /= 10;
		cnt++;
	}
	s = ft_calloc((cnt + 1), sizeof(char));
	if (!s)
		return (NULL);
	if (n < 0)
		*s = '-';
	while (cnt-- > (*s == '-'))
	{
		s[cnt] = (-1 * (n < 0)) * (n % 10) + '0';
		n /= 10;
	}
	return (s);
}
