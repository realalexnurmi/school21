/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isanum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:20:58 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:20:59 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Return [true] if string represent number, else [false]
t_bool	ft_isanum(char *s)
{
	while (ft_isspace(*s))
		s++;
	if ((*s == '-') || (*s == '+'))
		s++;
	while (ft_isdigit(*s))
	{
		s++;
		if (!(*s))
			return (true);
	}
	return (false);
}
