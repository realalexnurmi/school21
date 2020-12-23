/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zerroc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:05:04 by enena             #+#    #+#             */
/*   Updated: 2020/12/23 12:36:05 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_zerroc(size_t count, size_t size)
{
	void	*p_temp;

	p_temp = NULL;
	p_temp = malloc(count * size);
	if (p_temp)
	{
		ft_memset(p_temp, '0', count * size - 1);
		((char *)p_temp)[count * size - 1] = '\0';
	}
	return (p_temp);
}
