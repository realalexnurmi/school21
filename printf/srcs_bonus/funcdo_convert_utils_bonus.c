/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcdo_convert_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 23:38:38 by enena             #+#    #+#             */
/*   Updated: 2020/12/18 19:49:20 by enena            ###   ########.fr       */
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

char			*ft_take_space_plus(t_list_prf *lp, char *pr)
{
	char	*add;
	char	*ret;

	if ((lp->flag & SPCE_FLAG) || (lp->flag & PLUS_FLAG))
	{
		if (!(add = ft_calloc(2, sizeof(char))))
			return (NULL);
		if (lp->flag & SPCE_FLAG)
			add[0] = ((*pr == '-') ? '-' : ' ');
		else
			add[0] = ((*pr == '-') ? '-' : '+');
		if (!(ret = ft_strjoin(add, pr)))
			return (NULL);
		free(pr);
		free(add);
		return (ret);
	}
	return (pr);
}

char			*ft_hash(t_list_prf *lp, char *pr, t_bool isx)
{
	char	*ret;

	if (lp->flag & HASH_FLAG)
	{
		if (isx)
			ret = ft_strjoin("0x", pr);
		else
			ret = ft_strjoin("0", pr);
		if (!ret)
			return (NULL);
		free(pr);
		return (ret);
	}
	return (pr);
}