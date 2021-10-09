/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:21:23 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 17:02:23 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Convert all uppercase characters of string in lowercase
void	ft_lower(char *s)
{
	if (s)
	{
		while (*s)
		{
			*s = ft_tolower(*s);
			s++;
		}
	}
}
