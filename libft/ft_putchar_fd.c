/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:32:41 by enena             #+#    #+#             */
/*   Updated: 2020/12/11 21:26:36 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Upgraded putchar now work in UTF-8
** This get address printed char
** It work same with wide character in MultiByte and simple char
*/

void	ft_putchar_fd(char *c, int fd)
{
	if (!((*c & 0x80) && !(*c & 0x40)))
	{
		if ((*c & 0x80) == 0x00)
			write(fd, c, 1);
		if ((*c & 0xC0) == 0xC0 && !(*c & 0x20))
			write(fd, c, 2);
		if ((*c & 0xE0) == 0xE0 && !(*c & 0x10))
			write(fd, c, 3);
		if ((*c & 0xF0) == 0xF0 && !(*c & 0x08))
			write(fd, c, 4);
	}
}
