/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcdo_convert_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:40:06 by enena             #+#    #+#             */
/*   Updated: 2020/12/17 23:46:32 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long int	ft_take_signed(t_list_prf *curr)
{
	long long int	ret;

	ret = *((int *)curr->p_cnt);
	return (ret);
}

t_ullint		ft_take_unsigned(t_list_prf *curr)
{
	t_ullint	ret;

	ret = *((t_uint *)curr->p_cnt);
	return (ret);
}
