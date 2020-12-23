/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 22:02:48 by enena             #+#    #+#             */
/*   Updated: 2020/12/23 12:04:27 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function interprets an integer value in a byte string pointed to by [str].
** Discards any whitespace characters until the first
** non-whitespace character is found, then takes as many characters
** as possible to form a valid integer number representation
** and converts them to an integer value. Returns {long long int}
*/

long long int	ft_atoll(const char *str)
{
	long long int	ret;
	char			sign;

	ret = 0;
	sign = 1;
	while (*str && ft_isspace((int)*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') ? -1 : 1;
	while ((*str && ft_isdigit(*str)) && sign)
	{
		ret = ret * 10 + (*str - '0' * sign);
		if (ret && (ret * sign < 0))
			return (sign > 0 ? -1 : 0);
		str++;
	}
	return ((int)ret);
}
