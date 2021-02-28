/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 22:00:44 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:28:30 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function interprets an integer value in a byte string pointed to by [str].
** Discards any whitespace characters until the first
** non-whitespace character is found, then takes as many characters
** as possible to form a valid integer number representation
** and converts them to an integer value. Returns {long int}
*/

long int	ft_atol(const char *str)
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
		ret = ret * 10 + ((*str - '0') * sign);
		if (ret && (ret * sign < 0))
			return (sign > 0 ? -1 : 0);
		str++;
	}
	return ((int)ret);
}
