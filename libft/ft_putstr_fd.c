/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:22:43 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:22:45 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t	ft_putstr_fd(char *s, int fd)
{
	size_t len;

	len = 0;
	if (s)
	{
		len = ft_strlen(s);
		write(fd, s, len);
	}
	return (len);
}
