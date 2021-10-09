/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:22:41 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 16:22:42 by enena            ###   ########.fr       */
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
