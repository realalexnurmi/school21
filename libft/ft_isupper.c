/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:21:14 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:21:16 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Returns TRUE (1) if character uppercase letter, else FALSE (0)
t_bool	ft_isupper(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (true);
	else
		return (false);
}
