/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stous.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:22:53 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:22:54 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t		ft_stous(long long int signd)
{
	size_t	ret;

	if (signd < 0)
		ret = ~signd + 1;
	else
		ret = signd;
	return (ret);
}
