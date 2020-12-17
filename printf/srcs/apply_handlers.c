/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:13:45 by enena             #+#    #+#             */
/*   Updated: 2020/12/16 23:10:49 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool	ft_lstprf_apply_func_to_content(t_list_prf *curr)
{
	while (curr)
	{
		if (!(curr->func(curr)))
			return (FALSE);
		curr = curr->next;
	}
	return (TRUE);
}
