/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:26:43 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:32:10 by enena            ###   ########.fr       */
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
