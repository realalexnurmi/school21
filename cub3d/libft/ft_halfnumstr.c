/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_halfnumstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:12:53 by enena             #+#    #+#             */
/*   Updated: 2020/12/24 10:55:47 by enena            ###   ########.fr       */
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
