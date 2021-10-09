/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:18:38 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:18:43 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Like real atoi
//@Function interprets an integer value in a byte string pointed to by [str].
// Discards any whitespace characters until the first
// non-whitespace character is found, then takes as many characters
// as possible to form a valid integer number representation
// and converts them to an integer value. Returns {int}
int	ft_atoi(const char *str)
{
	long long int	ret;
	char			sign;

	ret = 0;
	while (*str && ft_isspace((int)*str))
		str++;
	sign = 1 - 2 * (*str == '-');
	str += (*str == '-' || *str == '+');
	while ((*str && ft_isdigit(*str)))
	{
		ret = ret * 10 + ((*str - '0') * sign);
		if (ret && (ret * sign < 0))
			return (-1 * (sign > 0));
		str++;
	}
	return ((int)ret);
}
