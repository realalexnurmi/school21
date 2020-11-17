/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:55:40 by enena             #+#    #+#             */
/*   Updated: 2020/11/13 22:54:09 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_my_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t'
			|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	unsigned int	res;
	char			np;

	res = 0;
	while (*str && ft_my_isspace((int)*str))
		str++;
	np = ((*str == '-') ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str && ft_isdigit((int)*str) && res <= (unsigned int)(-(INT_MIN)))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (((res > (unsigned int)(-(INT_MAX)) && np == -1)
				|| (res > INT_MAX && np == 1)))
		return ((np == 1) ? -1 : 0);
	return (res * np);
}
