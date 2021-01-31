/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_took_next_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:58:44 by enena             #+#    #+#             */
/*   Updated: 2020/12/15 00:24:46 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns pointer to next character in MultiByte string
*/

char	*ft_took_next_char(char *mbs)
{
	return (mbs + ft_mblen(mbs));
}
