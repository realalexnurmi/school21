/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mod_special_case.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:28:04 by enena             #+#    #+#             */
/*   Updated: 2020/12/21 21:46:12 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_check_modify(t_list_prf *curr, char *s)
{
	while (*++s)
	{
		if (*s == '0' && !(ft_isdigit(*(s - 1))) && *(s - 1) != '.')
			curr->flag |= ZERO_FLAG;
		if (*s == '-')
			curr->flag |= MNUS_FLAG;
	}
	ft_check_special_case(curr, (s - 1));
}

void	ft_check_special_case(t_list_prf *curr, char *s)
{
	if (curr->width && *(curr->width) < 0)
	{
		*(curr->width) *= -1;
		curr->flag |= MNUS_FLAG;
	}
	if (curr->prec && *(curr->prec) < 0)
	{
		free(curr->prec);
		curr->prec = NULL;
	}
	if (curr->flag & MNUS_FLAG)
		curr->flag &= (~(ZERO_FLAG));
	if (ft_isupper(*s))
		curr->flag = curr->flag | UPCS_FLAG;
	*s = ft_tolower(*s);
	if (curr->prec &&
			(*s == 'd' || *s == 'i' || *s == 'u' || *s == 'o' || *s == 'x'))
		curr->flag &= (~(ZERO_FLAG));
}
