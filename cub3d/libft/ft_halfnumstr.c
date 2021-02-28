/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_halfnumstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:12:53 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:30:09 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_halfnumstr(char *quo)
{
	char	*temp;
	char	newn;
	char	trans;

	temp = quo;
	trans = 0;
	while (*temp)
	{
		newn = (((trans * 10) + (*temp - '0')) / 2) + '0';
		trans = ((*temp - '0') % 2);
		*temp = newn;
		temp++;
	}
	return (quo);
}
