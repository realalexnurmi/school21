/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_free_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:14:08 by enena             #+#    #+#             */
/*   Updated: 2020/12/14 19:59:32 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	**ft_init_null_tab(char ***tab, size_t size)
{
	char	**curr;

	if (*tab)
	{
		curr = *tab;
		while (size--)
		{
			*curr = NULL;
			curr++;
		}
	}
	return (*tab);
}

void	ft_free_tab(char ***tab)
{
	char	**del;
	
	if (*tab)
	{
		del = *tab;
		while (*del)
		{
			free(*del);
			del++;
		}
		free(*tab);
		*tab = NULL;
	}
}

int		ft_error_escape_free(t_list_prf **list, char ***tab)
{
	ft_free_tab(tab);
	ft_lstprf_clear(list);
	return (-1);
}
