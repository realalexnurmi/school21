/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_handlers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 23:31:26 by enena             #+#    #+#             */
/*   Updated: 2020/12/17 18:20:45 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

t_bool	ft_lstprf_apply_func_to_content(t_list_prf *curr)
{
	long long int	offset;

	offset = 0;
	while (curr)
	{
		curr->ofst = offset;
		if (!(curr->func(curr)))
			return (FALSE);
		offset += ft_strlen(curr->print) - (curr->end - curr->begin + 1);
		curr = curr->next;
	}
	return (TRUE);
}
