/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_claim_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:29:00 by enena             #+#    #+#             */
/*   Updated: 2020/12/26 07:35:27 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool	ft_malloc_content(t_list_prf *curr, char conv)
{
	if (conv == 'c')
		curr->p_cnt = malloc(sizeof(char));
	if (conv == 's')
		curr->p_cnt = malloc(sizeof(char *));
	if (conv == 'p')
		curr->p_cnt = malloc(sizeof(void *));
	if ((conv == 'd') || (conv == 'i'))
		curr->p_cnt = malloc(sizeof(int));
	if ((conv == 'u') || (conv == 'x'))
		curr->p_cnt = malloc(sizeof(t_uint));
	return (!(curr->p_cnt) ? FALSE : TRUE);
}

t_bool	ft_claim_content(t_list_prf *curr, va_list *ap, char conv)
{
	if (!(ft_malloc_content(curr, conv)))
		return (FALSE);
	if (conv == 'c')
		*((char *)curr->p_cnt) = (char)va_arg(*ap, int);
	if (conv == 's')
		*((char **)curr->p_cnt) = va_arg(*ap, char *);
	if (conv == 'p')
		*((void **)curr->p_cnt) = va_arg(*ap, void *);
	if ((conv == 'd') || (conv == 'i'))
		*((int *)curr->p_cnt) = va_arg(*ap, int);
	if ((conv == 'u') || (conv == 'x'))
		*((t_uint *)curr->p_cnt) = va_arg(*ap, t_uint);
	return (TRUE);
}
