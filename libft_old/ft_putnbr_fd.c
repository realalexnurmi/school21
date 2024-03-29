/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 01:32:20 by enena             #+#    #+#             */
/*   Updated: 2020/12/12 17:45:32 by enena            ###   ########.fr       */
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
