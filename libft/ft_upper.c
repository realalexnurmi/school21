/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:26:11 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:26:12 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Convert all lowercase characters of string in uppercase
void	ft_upper(char *s)
{
	if (s)
	{
		while (*s)
		{
			*s = ft_toupper(*s);
			s++;
		}
	}
}
