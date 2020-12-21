/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   claim_size_content_funcs_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:35:32 by enena             #+#    #+#             */
/*   Updated: 2020/12/22 00:50:10 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_claim_l_content(t_list_prf *curr, va_list *ap, char conv)
{
	if ((conv == 'f') || (conv == 'e') || (conv == 'g'))
		*((double *)curr->p_cnt) = va_arg(*ap, double);
	if (conv == 'c')
		*((wchar_t *)curr->p_cnt) = (wchar_t)va_arg(*ap, wint_t);
	if (conv == 's')
		*((wchar_t **)curr->p_cnt) = va_arg(*ap, wchar_t *);
	if (conv == 'p')
		*((void **)curr->p_cnt) = va_arg(*ap, void *);
	if ((conv == 'd') || (conv == 'i'))
		*((long int *)curr->p_cnt) = va_arg(*ap, long int);
	if ((conv == 'o') || (conv == 'u') || (conv == 'x'))
		*((t_ulint *)curr->p_cnt) = va_arg(*ap, t_ulint);
	if (conv == 'n')
		*((long int **)curr->p_cnt) = va_arg(*ap, long int *);
}

void	ft_claim_ll_content(t_list_prf *curr, va_list *ap, char conv)
{
	if ((conv == 'f') || (conv == 'e') || (conv == 'g'))
		*((double *)curr->p_cnt) = va_arg(*ap, double);
	if (conv == 'c')
		*((wchar_t *)curr->p_cnt) = (wchar_t)va_arg(*ap, wint_t);
	if (conv == 's')
		*((wchar_t **)curr->p_cnt) = va_arg(*ap, wchar_t *);
	if (conv == 'p')
		*((void **)curr->p_cnt) = va_arg(*ap, void *);
	if ((conv == 'd') || (conv == 'i'))
		*((long long int *)curr->p_cnt) = va_arg(*ap, long long int);
	if ((conv == 'o') || (conv == 'u') || (conv == 'x'))
		*((t_ullint *)curr->p_cnt) = va_arg(*ap, t_ullint);
	if (conv == 'n')
		*((long long int **)curr->p_cnt) = va_arg(*ap, long long int*);
}

void	ft_claim_h_content(t_list_prf *curr, va_list *ap, char conv)
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

void	ft_claim_hh_content(t_list_prf *curr, va_list *ap, char conv)
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

void	ft_claim_z_content(t_list_prf *curr, va_list *ap, char conv)
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
