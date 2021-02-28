/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:54:20 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:28:54 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p_temp;

	p_temp = NULL;
	p_temp = malloc(count * size);
	if (p_temp)
		ft_bzero(p_temp, count * size);
	return (p_temp);
}
