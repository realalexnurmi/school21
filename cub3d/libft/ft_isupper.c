/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:26:04 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:31:56 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns TRUE (1) if character uppercase letter, else FALSE (0)
*/

t_bool	ft_isupper(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (true);
	else
		return (false);
}
