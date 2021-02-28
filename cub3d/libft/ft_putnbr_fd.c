/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 01:32:20 by enena             #+#    #+#             */
/*   Updated: 2021/02/27 00:34:38 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	ln;
	char		c;

	ln = (long int)n;
	if (ln < 0)
	{
		ft_putchar_fd("-", fd);
		ln = -ln;
	}
	if (ln >= 10)
		ft_putnbr_fd((ln / 10), fd);
	c = (ln % 10) + '0';
	ft_putchar_fd(&c, fd);
}
