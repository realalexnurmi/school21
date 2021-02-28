/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sumnumstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 08:21:58 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:36:32 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Function for adding numeric string
**	Second string need eqval or less length {NOSEG}
*/

void	ft_sumnumstr(char *sum, char *add)
{
	size_t	min;
	char	trans;

	sum += ft_strlen(sum) - 1;
	min = ft_strlen(add);
	add += min - 1;
	trans = 0;
	while (min > 0 || trans)
	{
		if (min)
			*sum = (*sum - '0') + (*add - '0') + '0';
		*sum += trans;
		trans = 0;
		if (*sum - '0' >= 10)
		{
			trans = 1;
			*sum -= 10;
		}
		if (min)
		{
			sum--;
			add--;
			min--;
		}
	}
}
