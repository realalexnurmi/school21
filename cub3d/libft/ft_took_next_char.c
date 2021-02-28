/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_took_next_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:58:44 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:37:03 by enena            ###   ########.fr       */
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
