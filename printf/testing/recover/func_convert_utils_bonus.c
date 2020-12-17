/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_convert_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:40:06 by enena             #+#    #+#             */
/*   Updated: 2020/12/15 17:05:22 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long int	ft_take_signed(t_list_prf *curr)
{
	long long int	ret;

	if (curr->size == NONE)
		ret = *((int *)curr->p_cnt);
	if (curr->size == L)
		ret = *((long int*)curr->p_cnt);
	if (curr->size == LL)
		ret = *((long long int*)curr->p_cnt);
	if (curr->size == H)
		ret = *((short int*)curr->p_cnt);
	if (curr->size == HH)
		ret = *((t_schar*)curr->p_cnt);
	if (curr->size == Z)
		ret = *((ssize_t*)curr->p_cnt);
	return (ret);
}

t_ullint		ft_take_unsigned(t_list_prf *curr)
{
	t_ullint	ret;

	if (curr->size == NONE)
		ret = *((t_uint *)curr->p_cnt);
	if (curr->size == L)
		ret = *((t_ulint*)curr->p_cnt);
	if (curr->size == LL)
		ret = *((t_ullint*)curr->p_cnt);
	if (curr->size == H)
		ret = *((t_usint*)curr->p_cnt);
	if (curr->size == HH)
		ret = *((t_uchar*)curr->p_cnt);
	if (curr->size == Z)
		ret = *((size_t*)curr->p_cnt);
	return (ret);
}
