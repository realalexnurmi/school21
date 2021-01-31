/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:38:37 by enena             #+#    #+#             */
/*   Updated: 2020/12/11 21:33:01 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns TRUE (1) if character letter or digit, else FALSE (0)
*/

t_bool	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
