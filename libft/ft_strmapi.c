/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:23:18 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:23:19 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	slen;

	if (!s)
		return (NULL);
	str = ft_strdup(s);
	if (!(str))
		return (NULL);
	slen = ft_strlen(str);
	while (slen--)
		str[slen] = f(slen, str[slen]);
	return (str);
}
