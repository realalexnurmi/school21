/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:40:19 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:29:21 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_free_tab(char **removetb)
{
	char	**tmp;

	tmp = removetb;
	while (*tmp)
	{
		*tmp = ft_sec_free(*tmp);
		tmp++;
	}
	return (removetb = ft_sec_free(removetb));
}
