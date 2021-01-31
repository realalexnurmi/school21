/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:17:28 by enena             #+#    #+#             */
/*   Updated: 2020/12/15 17:26:19 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convert all lowercase characters of string in uppercase
*/

void	ft_upper(char *s)
{
	if (s)
		while (*s)
		{
			*s = ft_toupper(*s);
			s++;
		}
}
