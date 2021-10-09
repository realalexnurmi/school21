/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:20:52 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:20:55 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Returns [true] if character letter or digit, else [false]
t_bool	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
