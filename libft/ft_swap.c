/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:25:58 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:25:59 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
t_bool	ft_swap(void *v1, void *v2, size_t size)
{
	void	*v3;

	v3 = malloc(size);
	if (!(v3))
		return (false);
	ft_memmove(v3, v1, size);
	ft_memmove(v1, v2, size);
	ft_memmove(v2, v3, size);
	free(v3);
	return (true);
}
