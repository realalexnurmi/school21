/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:19:02 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:19:03 by enena            ###   ########.fr       */
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
