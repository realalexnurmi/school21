/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zerroc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:05:04 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:37:47 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_zerroc(size_t count)
{
	char	*p_temp;

	p_temp = NULL;
	p_temp = malloc((count + 1) * sizeof(char));
	if (p_temp)
	{
		ft_memset(p_temp, '0', count);
		p_temp[count] = '\0';
	}
	return (p_temp);
}
