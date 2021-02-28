/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stous.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 20:43:08 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:35:10 by enena            ###   ########.fr       */
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
