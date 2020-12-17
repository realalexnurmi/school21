/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:26:43 by enena             #+#    #+#             */
/*   Updated: 2020/12/15 17:28:08 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convert all uppercase characters of string in lowercase
*/

void	ft_lower(char *s)
{
	if (s)
		while (*s)
		{
			*s = ft_tolower(*s);
			s++;
		}
}
