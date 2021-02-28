/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 00:16:33 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:36:48 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_swap(void *v1, void *v2, size_t size)
{
	void	*v3;

	v3 = NULL;
	if (!(v3 = malloc(size)))
		return (false);
	ft_memmove(v3, v1, size);
	ft_memmove(v1, v2, size);
	ft_memmove(v2, v3, size);
	free(v3);
	return (true);
}
