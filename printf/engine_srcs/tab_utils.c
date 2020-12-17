/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:56:24 by enena             #+#    #+#             */
/*   Updated: 2020/12/16 23:01:24 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "libftprintf_bonus.h"
#else
# include "libftprintf.h"
#endif

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
