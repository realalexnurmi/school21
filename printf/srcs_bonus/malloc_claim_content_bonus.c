/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_claim_content_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 00:07:13 by enena             #+#    #+#             */
/*   Updated: 2020/12/18 19:50:10 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool	ft_malloc_content(t_list_prf *curr, char conv)
{
	if (curr->size == NONE)
	{
		if ((conv == 'f') || (conv == 'e') || (conv == 'g'))
			curr->p_cnt = malloc(sizeof(double));
		if (conv == 'c')
			curr->p_cnt = malloc(sizeof(char));
		if (conv == 's')
			curr->p_cnt = malloc(sizeof(char *));
		if (conv == 'p')
			curr->p_cnt = malloc(sizeof(void *));
		if ((conv == 'd') || (conv == 'i'))
			curr->p_cnt = malloc(sizeof(int));
		if ((conv == 'o') || (conv == 'u') || (conv == 'x'))
			curr->p_cnt = malloc(sizeof(t_uint));
		if (conv == 'n')
			curr->p_cnt = malloc(sizeof(int *));
	}
	else
		ft_malloc_size_content(curr, conv);
	return (!(curr->p_cnt) ? FALSE : TRUE);
}

void	ft_malloc_size_content(t_list_prf *curr, char conv)
{
	if (curr->size == L)
		ft_malloc_l_content(curr, conv);
	if (curr->size == LL)
		ft_malloc_ll_content(curr, conv);
	if (curr->size == H)
		ft_malloc_h_content(curr, conv);
	if (curr->size == HH)
		ft_malloc_hh_content(curr, conv);
	if (curr->size == Z)
		ft_malloc_z_content(curr, conv);
}

t_bool	ft_claim_content(t_list_prf *curr, va_list *ap, char conv)
{
	if (((conv == 'c') || (conv == 's')) && (curr->flag & UPCS_FLAG))
		curr->size = L;
	if (!(ft_malloc_content(curr, conv)))
		return (FALSE);
	if (curr->size == NONE)
	{
		if ((conv == 'f') || (conv == 'e') || (conv == 'g'))
			*((double *)curr->p_cnt) = va_arg(*ap, double);
		if (conv == 'c')
			*((char *)curr->p_cnt) = (char)va_arg(*ap, int);
		if (conv == 's')
			*((char **)curr->p_cnt) = va_arg(*ap, char *);
		if (conv == 'p')
			*((void **)curr->p_cnt) = va_arg(*ap, void *);
		if ((conv == 'd') || (conv == 'i'))
			*((int *)curr->p_cnt) = va_arg(*ap, int);
		if ((conv == 'o') || (conv == 'u') || (conv == 'x'))
			*((t_uint *)curr->p_cnt) = va_arg(*ap, t_uint);
		if (conv == 'n')
			*((int **)curr->p_cnt) = va_arg(*ap, int*);
	}
	else
		ft_claim_size_content(curr, ap, conv);
	return (TRUE);
}

void	ft_claim_size_content(t_list_prf *curr, va_list *ap, char conv)
{
	if (curr->size == L)
		ft_claim_l_content(curr, ap, conv);
	if (curr->size == LL)
		ft_claim_ll_content(curr, ap, conv);
	if (curr->size == H)
		ft_claim_h_content(curr, ap, conv);
	if (curr->size == HH)
		ft_claim_hh_content(curr, ap, conv);
	if (curr->size == Z)
		ft_claim_z_content(curr, ap, conv);
}
