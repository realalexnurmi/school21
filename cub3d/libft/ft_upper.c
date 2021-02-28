/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:17:28 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:37:24 by enena            ###   ########.fr       */
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
