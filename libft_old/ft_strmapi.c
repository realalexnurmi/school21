/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:32:39 by enena             #+#    #+#             */
/*   Updated: 2020/11/10 22:27:59 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	slen;

	if (!s)
		return (NULL);
	if (!(str = ft_strdup(s)))
		return (NULL);
	slen = ft_strlen(str);
	while (slen--)
		str[slen] = f(slen, str[slen]);
	return (str);
}
