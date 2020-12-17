/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_escape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:56:50 by enena             #+#    #+#             */
/*   Updated: 2020/12/16 22:58:38 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "libftprintf_bonus.h"
#else
# include "libftprintf.h"
#endif

int	ft_error_escape(t_list_prf **list, char ***tab)
{
	ft_free_tab(tab);
	ft_lstprf_clear(list);
	return (-1);
}
