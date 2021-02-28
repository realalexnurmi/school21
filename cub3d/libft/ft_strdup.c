/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:32:28 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:35:22 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p_copy;
	size_t	len;

	len = ft_strlen(s);
	if (!(p_copy = ft_calloc(len + 1, sizeof(char))) || !s)
		return (NULL);
	while (len--)
		p_copy[len] = s[len];
	return (p_copy);
}
