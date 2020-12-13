/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:28:59 by enena             #+#    #+#             */
/*   Updated: 2020/12/12 17:42:02 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns TRUE (1) if character letter, else FALSE (0)
** Adapted only for standart "C" locale
*/

t_bool	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
