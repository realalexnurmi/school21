/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stous.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 20:43:08 by enena             #+#    #+#             */
/*   Updated: 2020/12/26 20:52:30 by enena            ###   ########.fr       */
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
